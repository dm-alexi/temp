<?php
include_once('Lannister.class.php');
class Tyrion extends Lannister
{
    public function sleepWith($person)
    {
        if ($person instanceof Sansa)
            print ("Let's do this.\n");
        else
            parent::sleepWith($person);
    }
}
?>