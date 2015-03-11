<?php
/**
 * @file
 * nodes_with_pictures.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function nodes_with_pictures_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Accessories',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 10,
    'uuid' => '040fd5e5-0fa8-4e14-8acf-e26c173d32d3',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 296,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Winter',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '0e755824-37df-41dc-8616-faa7a332fb10',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 222,
        ),
      ),
    ),
    'parent' => array(
      0 => '2fc66909-8bac-4e96-b25d-8e0c33f1f1ef',
    ),
  );
  $terms[] = array(
    'name' => 'Accessories Men',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '13acc841-c422-4b20-83b6-897b1f1576a2',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 666,
        ),
      ),
    ),
    'parent' => array(
      0 => '040fd5e5-0fa8-4e14-8acf-e26c173d32d3',
    ),
  );
  $terms[] = array(
    'name' => 'Jewelry',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 12,
    'uuid' => '18cc380d-42f4-4431-abd4-cd5eee820c72',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 29,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Footwear',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 11,
    'uuid' => '2fc66909-8bac-4e96-b25d-8e0c33f1f1ef',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 107,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Dresses',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '32ad29fe-80ed-4175-a1eb-7b7f91aee82e',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 163,
        ),
      ),
    ),
    'parent' => array(
      0 => '4b641591-11ab-4f77-94eb-faa7d03c6dd9',
    ),
  );
  $terms[] = array(
    'name' => 'Men',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 13,
    'uuid' => '445c6830-f336-428c-a942-892e2e2f8140',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 33,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Women',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 14,
    'uuid' => '4b641591-11ab-4f77-94eb-faa7d03c6dd9',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 36,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Imitation jewelry',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '4cd12449-1e2f-41ca-93c0-faa705315abb',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 26,
        ),
      ),
    ),
    'parent' => array(
      0 => '18cc380d-42f4-4431-abd4-cd5eee820c72',
    ),
  );
  $terms[] = array(
    'name' => 'Jackets and tops',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '877dcdfd-6090-4225-b31a-ddd0b6608200',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 41,
        ),
      ),
    ),
    'parent' => array(
      0 => '4b641591-11ab-4f77-94eb-faa7d03c6dd9',
    ),
  );
  $terms[] = array(
    'name' => 'Jackets',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '8de16ed2-7551-4d23-b47f-f723631a0cd2',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 41,
        ),
      ),
    ),
    'parent' => array(
      0 => '445c6830-f336-428c-a942-892e2e2f8140',
    ),
  );
  $terms[] = array(
    'name' => 'Summer',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '8e6b292c-1a51-428c-addf-b9c7e4131576',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 92,
        ),
      ),
    ),
    'parent' => array(
      0 => '2fc66909-8bac-4e96-b25d-8e0c33f1f1ef',
    ),
  );
  $terms[] = array(
    'name' => 'Tops',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b89a9a6d-6204-4bb9-b8ad-64bae86ffe45',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 56,
        ),
      ),
    ),
    'parent' => array(
      0 => '445c6830-f336-428c-a942-892e2e2f8140',
    ),
  );
  $terms[] = array(
    'name' => 'Bags and Wallets',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'c08b4e07-be83-4bc2-a470-a22e453858d3',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 152,
        ),
      ),
    ),
    'parent' => array(
      0 => '040fd5e5-0fa8-4e14-8acf-e26c173d32d3',
    ),
  );
  $terms[] = array(
    'name' => 'Diamond rings',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cd70fe1d-7545-447b-acba-b375b2bc7a6e',
    'vocabulary_machine_name' => 'categories',
    'field_count' => array(
      'und' => array(
        0 => array(
          'value' => 72,
        ),
      ),
    ),
    'parent' => array(
      0 => '18cc380d-42f4-4431-abd4-cd5eee820c72',
    ),
  );
  return $terms;
}
