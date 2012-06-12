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

?>
<script type="text/javascript">
$.get('/siteclone/rpc?id=<?=htmlspecialchars($_GET['id'])?>', function(data) {
    $('#result').html(data);
    $('#progress').hide();
});
</script>

<?php
