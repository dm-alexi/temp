<?php
abstract class Fighter
{
    protected $_type;

    public function getType() { return $this->_type; }

    public function __construct($arg)
    {
        $this->_type = $arg;
    }

    abstract protected function fight($target);
}
?>