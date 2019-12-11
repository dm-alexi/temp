<?php
require_once 'Camera.class.php';
class Triangle
{
    public static $verbose = false;
	public static function doc()
	{
		return file_get_contents('Triangle.doc.txt');
    }

    private $_a;    
    private $_b;
    private $_c;
    private $_dots;

    public function getA() { return $this->_a; }
    public function getB() { return $this->_b; }
    public function getC() { return $this->_c; }
    public function getDots() { return $this->_dots; }
    
    public function __construct($a, $b, $c)
    {
        $this->_a = $a;
        $this->_b = $b;
        $this->_c = $c;
        $this->_dots = array($this->getA(), $this->getB(), $this->getC());
        if (self::$verbose)
            echo "Triangle instance constructed\n";
    }
    
    public function __destruct()
	{
		if (self::$verbose)
            printf("Triangle instance destructed\n");
        return;
	}
	
    public function __toString()
	{
        return sprintf("Triangle\n(\n A : %s,\n B: %s,\n C: %s\n)", $this->getA(), $this->getB(), $this->getC());
    }
}