<?php

//$message = ;
$message = lang::translate('siteclone_rpc_please_wait_message');

?>
<div id="progress">
    <h3><?=$message?></h3>
    <img src="/images/load.gif" width="16" />
</div>
<div id ="result">
    
</div>
<?php

template::setTitle(lang::translate('siteclone_confirm_html_title'));

$clone = new siteclone();
$row = $clone->getRowFromMD5($_GET['id']);
$sitename = $row['sitename'];

$sitename.= '.' . config::getMainIni('server_name');
?>
<script type="text/javascript">
    $.get('/siteclone/rpc?id=<?=htmlspecialchars($_GET['id'])?>', function(data) {
  $('#result').html(data);
  //window.location.href = "http://<?=$sitename?>";
  //alert('Load was performed.');
  $('#progress').hide();
});
</script>

<?php



/*
$js = '';
$clone = new siteclone();
if (!empty($_POST)) {
    $clone->validateCaptcha();
    if (!empty($clone->errors)) {
        view_form_errors($clone->errors);
        $js = "var siteclone_display = false;";        
    } else {
        echo "huha";
        
        
    }
}

$js = "var siteclone_display = true;";

template::setStringJs($js);
template::setInlineJs(config::getModulePath('siteclone') . '/siteclone.js');
template::setInlineCss(config::getModulePath('siteclone') . '/siteclone.css');

$clone->confirmForm();
 */
 