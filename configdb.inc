<?php

$db_config = array (
    array ('name' => 'siteclone_conditions', 
           'description' => lang::translate('siteclone_initial_conditions_config_title'),
           'type' => 'textarea', 
           'extra' => array ('id' => 'markdown'),
           'value' => lang::translate('siteclone_initial_conditions'),
           'auth' => 'admin'),
);

$db_config_menu = true;