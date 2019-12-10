<?php
require_once 'Vector.class.php';
Class Vector
{
	public static $verbose = false;
	public static function doc()
	{
		return file_get_contents('Vector.doc.txt');
	}
	
	private $_x;
	private $_y;
    private $_z;
    private $_w;

    public function getX() { return $this->_x; }
    public function getY() { return $this->_y; }
    public function getZ() { return $this->_z; }
    public function getW() { return $this->_w; }

	public function __construct(array $args)
	{
        $orig = array_key_exists('orig', $args) ? $args['orig'] : new Vertex(array('x' => 0, 'y' => 0, 'z' => 0, 'w' => 1));
        $this->_x = $args['dest']->getX() - $orig->getX();
        $this->_y = $args['dest']->getY() - $orig->getY();
        $this->_z = $args['dest']->getZ() - $orig->getZ();
        $_w = 0.0;
		if (self::$verbose)
			printf("%s constructed\n", $this);
		return;
	}

	public function __destruct()
	{
		if (self::$verbose)
            printf("%s destructed\n", $this);
        return;
	}

	public function __toString()
	{
        return sprintf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f )", $this->_x, $this->_y, $this->_z, $this->_w);
    }
    
    public function magnitude()
    {
        return sqrt($this->getX() * $this->getX() + $this->getY() * $this->getY() + $this->getZ() * $this->getZ());
    }

    public function normalize()
    {
        $norm = $this->magnitude();
        return new Vector(array('dest' => new Vertex(array('x' => $this->getX() / $norm, 'y' => $this->getY() / $norm, 'z' => $this->getZ() / $norm))));
    }

    public function add(Vector $rhs)
    {
        return new Vector(array('dest' => new Vertex(array('x' => $this->getX() + $rhs->getX(), 'y' => $this->getY() + $rhs->getY(), 'z' => $this->getZ() + $rhs->getZ()))));
    }

    public function sub(Vector $rhs)
    {
        return new Vector(array('dest' => new Vertex(array('x' => $this->getX() - $rhs->getX(), 'y' => $this->getY() - $rhs->getY(), 'z' => $this->getZ() - $rhs->getZ()))));
    }

    public function opposite()
    {
        return new Vector(array('dest' => new Vertex(array('x' => -$this->getX() , 'y' => -$this->getY(), 'z' => -$this->getZ()))));
    }

    public function scalarProduct($k)
    {
        return new Vector(array('dest' => new Vertex(array('x' => $this->getX() * $k, 'y' => $this->getY() * $k, 'z' => $this->getZ() * $k))));
    }

    public function dotProduct(Vector $rhs)
    {
        return $this->getX() * $rhs->getX() + $this->getY() * $rhs->getY() + $this->getZ() * $rhs->getZ();
    }

    public function cos(Vector $rhs)
    {
        return $this->dotProduct($rhs) / ($this->magnitude() * $rhs->magnitude());
    }

    public function crossProduct(Vector $rhs)
    {
        $cx = $this->getY() * $rhs->getZ() - $this->getZ() * $rhs->getY();
        $cy = $this->getZ() * $rhs->getX() - $this->getX() * $rhs->getZ();
        $cz = $this->getX() * $rhs->getY() - $this->getY() * $rhs->getX();
        return new Vector(array('dest' => new Vertex(array('x' => $cx, 'y' => $cy, 'z' => $cz))));
    }
}
?>