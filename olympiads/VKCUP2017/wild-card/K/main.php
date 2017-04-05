<?php
$stdin = fopen('php://stdin', 'r');
$stdout = fopen('php://stdout', 'w');

$s1 = fgets($stdin);
$s = "0" . substr(fgets($stdin), 0, -1) . "0";

$L = strlen($s);

$res = "";
$gl = array("a", "e", "i", "o", "u", "y");
$gl_sp = array("o", "e");
$count = 0;
for($i = 1; $i < $L; $i++)
{
    if($s[$i] == $s[$i - 1])
    {
        $count++;
    }
    else
    {
        $pr = $s[$i - 1];
        if(in_array($pr, $gl_sp) && $count == 2)
        {
	    $res .= str_repeat($pr, $count);
        }
        else if(in_array($pr, $gl))
        {
            $res .= str_repeat($pr, $count > 0 ? 1 : 0);
        }
        else
        {
            $res .= str_repeat($pr, $count);
        }
        $count = 1;
    }
}

fputs($stdout, $res . "\n");
?>
