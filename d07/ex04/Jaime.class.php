<?php
include_once('Lannister.class.php');
class Jaime extends Lannister
{
    public function sleepWith($person)
    {
        if ($person instanceof Sansa)
            print ("Let's do this.\n");
        else if ($person instanceof Cersei)
            print ("With pleasure, but only in a tower in Winterfell, then.\n");
        else
            parent::sleepWith($person);
    }
}
?>