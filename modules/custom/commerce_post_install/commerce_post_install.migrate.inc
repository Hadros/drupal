<?php

abstract class CommerceProfileMigration extends Migration {

  public function processImport(array $options = array()) {
    parent::processImport($options);
    // Do not force menu rebuilding. Otherwise pathauto will try to rebuild
    // in each node_insert invocation.
    variable_set('menu_rebuild_needed', FALSE);
  }
}

class CommerceProfileProductsMigration extends CommerceProfileMigration {

  public function __construct() {
    parent::__construct();
    $this->description = t('Import products from CSV file.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'sku' => array(
          'type' => 'varchar',
          'length' => 32,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationEntityAPI::getKeySchema('commerce_product')
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'commerce_post_install') . '/import/products.csv', $this->csvcolumns(), array('header_rows' => 1), $this->fields());
    dsm($this->source);

    $this->destination = new MigrateDestinationEntityAPI('commerce_product', 'product');

    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('sku', 'sku');
    $this->addFieldMapping('commerce_price', 'price');

    // Images
    /*$this->addFieldMapping('field_view', 'images');
    $this->addFieldMapping('field_view:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_view:source_dir')
      ->defaultValue(drupal_get_path('module', 'commerce_post_install') . '/import/images');

    // Specifications
    $this->addFieldMapping('field_specifications', 'specifications');
    
    // Description
    $this->addFieldMapping('field_description', 'description');

    // Rating
    $this->addFieldMapping('field_rating', 'rating');
    
    $this->addFieldMapping('uid', 'uid');
    $this->addFieldMapping('language', 'language');*/
  }

  function csvcolumns() {
    // "title","SKU","Color","Size","Price","Images"
    $columns[6] = array('title', 'Title');
    $columns[4] = array('sku', 'SKU');
    $columns[0] = array('description', 'Description');
    $columns[3] = array('rating', 'Rating');
    $columns[2] = array('price', 'Price');
    $columns[1] = array('images', 'Image');
    $columns[5] = array('specifications', 'Specifications');
    return $columns;
  }

  function fields() {
    return array(
      'product_images' => 'An array of images, populated during prepareRow().',
    );
  }

  function prepareRow($row) {
    $row->product_images = explode(', ', $row->images);
    $row->uid = 1;
    $row->language = LANGUAGE_NONE;
  }
}