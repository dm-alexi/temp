<?php
require_once 'Matrix.class.php';
class Camera
{
    public static $verbose = false;
	public static function doc()
	{
		return file_get_contents('Camera.doc.txt');
    }

    private $_origin;    
    private $_tR;
    private $_tT;
    private $_width;
    private $_height;
    private $_ratio;
    private $_projection;

    public function getOrigin() { return $this->_origin; }
    public function getTR() { return $this->_tR; }
    public function getTT() { return $this->_tT; }
    public function getRatio() { return $this->_ratio; }
    public function getProjection() { return $this->_projection; }

    public function __construct($args)
    {
        $this->_origin = $args['origin'];
        $this->_tT = new Matrix(array('preset' => Matrix::TRANSLATION, 'vtc' => (new Vector(array('dest' => $this->getOrigin())))->opposite()));
        $this->_ratio = isset($args['ratio']) ? $args['ratio'] : floatval($args['width']) / floatval($args['height']);
        $this->_tR = new Matrix(array('transpose' => $args['orientation']));
        $this->_projection = new Matrix(array('preset' => Matrix::PROJECTION, 'fov' => $args['fov'], 'ratio' => $this->_ratio, 'near' => $args['near'], 'far' => $args['far'] ));
        if (self::$verbose)
            echo "Camera instance constructed\n";
    }
    
    public function watchVertex(Vertex $worldVertex)
    {
        $vtx = $this->getProjection()->transformVertex($this->getTR()->transformVertex($worldVertex));
        $vtx->setX($vtx->getX() * $this->getRatio());
        $vtx->setY($vtx->getY());
        $vtx->setColor($worldVertex->getColor());
        return ($vtx);
    }

    public function __destruct()
	{
		if (self::$verbose)
            printf("Camera instance destructed\n");
        return;
	}
	
    public function __toString()
	{
        return sprintf("Camera( \n+ Origine: %s\n+ tT:\n%s\n+ tR:\n%s\n+ tR->mult( tT ):\n%s\n+ Proj:\n%s\n)", $this->getOrigin(), $this->getTT(), $this->getTR(), $this->getTR()->mult($this->getTT()), $this->_projection);
    }

    public function watchMesh($mesh)
    {
        $res = array();
        foreach ($mesh as $key => $val)
            $res[$key] = new Triangle($this->watchVertex($val->getA()), $this->watchVertex($val->getB()), $this->watchVertex($val->getC()));
        return $res;
    }
}
