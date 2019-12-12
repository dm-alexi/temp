<?php
class UnholyFactory
{
    private $_fighters = array();
    
    public function absorb($unit)
    {
        if (!($unit instanceof Fighter))
            print("(Factory can't absorb this, it's not a fighter)" . PHP_EOL);
        else if (array_key_exists($unit->getType(), $this->_fighters))
            print("(Factory already absorbed a fighter of type " . $unit->getType() . ")" . PHP_EOL);
        else
        {
            $this->_fighters[$unit->getType()] = $unit;
            print("(Factory absorbed a fighter of type " . $unit->getType() . ")" . PHP_EOL);
        }
    }

    public function fabricate($type)
    {
        if (array_key_exists($type, $this->_fighters))
        {
            print("(Factory fabricates a fighter of type " . $type . ")" . PHP_EOL);
            return clone $this->_fighters[$type];
        }
        print("(Factory hasn't absorbed any fighter of type " . $type . ")" . PHP_EOL);
        return NULL;
    }
}
?>