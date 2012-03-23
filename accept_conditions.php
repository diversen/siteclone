<?php

//template::init('js-toc');
moduleLoader::includeTemplateCommon('js-toc');
$options = array ('exclude' => '', 'context' => '#siteclone_conditions');
jstoc_set_toc($options);

$conditions = config::getModuleIni('siteclone_conditions');
$conditions = get_filtered_content(array('markdown'), $conditions);

echo "<div id=\"toc\"></div>\n";
echo '<div id="#siteclone_conditions">';
echo $conditions;
echo '</div>';