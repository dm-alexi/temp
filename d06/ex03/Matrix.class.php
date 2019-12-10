<?php
require_once 'Vector.class.php';
Class Matrix
{
	public static $verbose = false;
	public static function doc()
	{
		return file_get_contents('Matrix.doc.txt');
	}

    const IDENTITY = 1;
    const SCALE = 2;
    const RX = 3;
    const RY = 4;
    const RZ = 5;
    const TRANSLATION = 6;
    const PROJECTION = 7;

	private $_vectorX;
	private $_vectorY;
    private $_vectorZ;
    private $_vector0;

    public function getVectorX() { return $this->_vectorX; }
    public function getVectorY() { return $this->_vectorY; }
    public function getVectorZ() { return $this->_vectorZ; }
    public function getVector0() { return $this->_vector0; }

	public function __construct(array $args)
	{
        switch($args['preset'])
        {
            case self::IDENTITY:
                $_vectorX = new Vector(array('dest' => new Vertex(array('x' => 1, 'y' => 0, 'z' => 0, 'w' => 0))));
                $_vectorY = new Vector(array('dest' => new Vertex(array('x' => 0, 'y' => 1, 'z' => 0, 'w' => 0))));
                $_vectorZ = new Vector(array('dest' => new Vertex(array('x' => 0, 'y' => 0, 'z' => 1, 'w' => 0))));
                $_vector0 = new Vector(array('dest' => new Vertex(array('x' => 0, 'y' => 0, 'z' => 0, 'w' => 1))));
                break;
            case self::SCALE:
                $_vectorX = new Vector(array('dest' => new Vertex(array('x' => $args['scale'], 'y' => 0, 'z' => 0, 'w' => 0))));
                $_vectorY = new Vector(array('dest' => new Vertex(array('x' => 0, 'y' => $args['scale'], 'z' => 0, 'w' => 0))));
                $_vectorZ = new Vector(array('dest' => new Vertex(array('x' => 0, 'y' => 0, 'z' => $args['scale'], 'w' => 0))));
                $_vector0 = new Vector(array('dest' => new Vertex(array('x' => 0, 'y' => 0, 'z' => 0, 'w' => 1))));
                break;
        }
        /*
        if (self::$verbose)
            printf("%s constructed\n", $this);
            */
		return;
	}

	public function __destruct()
	{
		if (self::$verbose)
            printf("Matrix instance destructed\n", $this);
        return;
	}
/*
	public function __toString()
	{
        return sprintf("M | vtcX | vtcY | vtcZ | vtxO\n-----------------------------\n", $this->_x, $this->_y, $this->_z, $this->_w);
    }
    */
    public function mult(Matrix $rhs)
    {
        ;
    }

    public function transformVertex(Vertex $vtx)
    {
        ;
    }
    
}
?>