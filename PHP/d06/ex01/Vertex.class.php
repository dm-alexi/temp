<?php
require_once 'Color.class.php';
Class Vertex
{
	public static $verbose = false;
	public static function doc()
	{
		return file_get_contents('Vertex.doc.txt');
	}
	
	private $_x;
	private $_y;
    private $_z;
    private $_w;
    private $_color;

    public function getX() { return $this->_x; }
    public function getY() { return $this->_y; }
    public function getZ() { return $this->_z; }
    public function getW() { return $this->_w; }
    public function getColor() { return $this->_color; }
    public function setX( $v ) { $this->_x = floatval($v); return; }
    public function setY( $v ) { $this->_y = floatval($v); return; }
    public function setZ( $v ) { $this->_z = floatval($v); return; }
    public function setW( $v ) { $this->_w = floatval($v); return; }
    public function setColor( Color $v ) { $this->_color = $v; return; }

	public function __construct(array $args)
	{
        $this->setX($args['x']);
        $this->setY($args['y']);
        $this->setZ($args['z']);
        $this->setW(array_key_exists('w', $args) ? $args['w'] : 1.0);
        $this->setColor(array_key_exists('color', $args) ? $args['color'] : new Color(array('rgb' => 0xFFFFFF)));
		if (self::$verbose)
			printf("%s constructed\n", $this);
		return;
	}

	public function __destruct()
	{
		if (self::$verbose)
			printf("%s destructed\n", $this);
	}

	public function __toString()
	{
        return sprintf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f", $this->_x, $this->_y, $this->_z, $this->_w) . (self::$verbose ? ", " . $this->_color : "") . " )";    
	}
}
?>