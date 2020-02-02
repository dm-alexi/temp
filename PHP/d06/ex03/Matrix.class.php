<?php
require_once 'Vector.class.php';
Class Matrix
{
	public static $verbose = false;
	public static function doc()
	{
		return file_get_contents('Matrix.doc.txt');
	}

	const IDENTITY = "IDENTITY";
	const SCALE = "SCALE";
	const RX = "Ox ROTATION";
	const RY = "Oy ROTATION";
	const RZ = "Oz ROTATION";
	const TRANSLATION = "TRANSLATION";
	const PROJECTION = "PROJECTION";

	private $_matrix;

    public function getMatrix() { return $this->_matrix; }

	public function __construct(array $args)
	{
	    if (isset($args['preset']))
	    {  
	        switch($args['preset'])
            {
                case self::IDENTITY:
                    $this->_matrix = array(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
                    break;
                case self::SCALE:
                    $this->_matrix = array($args['scale'], 0, 0, 0, 0, $args['scale'], 0, 0, 0, 0, $args['scale'], 0, 0, 0, 0, 1);
                    break;
    	       case self::RX:
    	           $this->_matrix = array(1, 0, 0, 0, 0, cos($args['angle']), -sin($args['angle']), 0, 0, sin($args['angle']), cos($args['angle']), 0, 0, 0, 0, 1);
                    break;
    	       case self::RY:
    	           $this->_matrix = array(cos($args['angle']), 0, sin($args['angle']), 0, 0, 1, 0, 0, -sin($args['angle']), 0, cos($args['angle']), 0, 0, 0, 0, 1);
                    break;
    	       case self::RZ:
    	           $this->_matrix = array(cos($args['angle']), -sin($args['angle']), 0, 0, sin($args['angle']), cos($args['angle']), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
                    break;
    	       case self::TRANSLATION:
    	           $this->_matrix = array(1, 0, 0,  $args['vtc']->getX(), 0, 1, 0, $args['vtc']->getY(), 0, 0, 1, $args['vtc']->getZ(), 0, 0, 0, 1);
                    break;
    	       case self::PROJECTION:
    	           $tanFov = tan(deg2rad($args['fov'] / 2));
    	           $this->_matrix = array(1 / ($tanFov * $args['ratio']), 0, 0, 0, 0, 1 / $tanFov, 0, 0, 0, 0, -($args['far'] + $args['near'])/($args['far'] - $args['near']), 2 * $args['far'] * $args['near'] / ($args['near'] - $args['far']), 0, 0, -1, 0);
                    break;
            }
            if (self::$verbose)
                printf("Matrix %s%s instance constructed\n", $args['preset'], $args['preset'] === self::IDENTITY ? "" : " preset");
	    }
	    else if (isset($args[0]) && isset($args[1]))
	    {
	        for ($i = 0; $i < 4; ++$i)
	            for ($j = 0; $j < 4; ++$j)
	            {
	                $s = 0;
	                for ($k = 0; $k < 4; ++$k)
	                    $s += $args[0]->getMatrix()[$i * 4 + $k] *  $args[1]->getMatrix()[$k * 4 + $j];
	                $this->_matrix[$i * 4 + $j] = $s;
	            }
	    }
		return;
	}

	public function __destruct()
	{
		if (self::$verbose)
            printf("Matrix instance destructed\n");
        return;
	}
	
	public function __toString()
	{
	    return sprintf("M | vtcX | vtcY | vtcZ | vtxO\n-----------------------------\nx | %.2f | %.2f | %.2f | %.2f\ny | %.2f | %.2f | %.2f | %.2f\nz | %.2f | %.2f | %.2f | %.2f\nw | %.2f | %.2f | %.2f | %.2f",
	        $this->_matrix[0], $this->_matrix[1], $this->_matrix[2], $this->_matrix[3], $this->_matrix[4], $this->_matrix[5], $this->_matrix[6], $this->_matrix[7],
	        $this->_matrix[8], $this->_matrix[9], $this->_matrix[10], $this->_matrix[11], $this->_matrix[12], $this->_matrix[13], $this->_matrix[14], $this->_matrix[15]);
    }

    public function mult(Matrix $rhs)
    {
        return new Matrix(array($this, $rhs));
    }

    public function transformVertex(Vertex $vtx)
    {
        return new Vertex( array(
            'x' => $vtx->getX() * $this->_matrix[0] +  $vtx->getY() * $this->_matrix[1] + $vtx->getZ() * $this->_matrix[2] +  $vtx->getW() * $this->_matrix[3],
            'y' => $vtx->getX() * $this->_matrix[4] +  $vtx->getY() * $this->_matrix[5] + $vtx->getZ() * $this->_matrix[6] +  $vtx->getW() * $this->_matrix[7],
            'z' => $vtx->getX() * $this->_matrix[8] +  $vtx->getY() * $this->_matrix[9] + $vtx->getZ() * $this->_matrix[10] +  $vtx->getW() * $this->_matrix[11],
            'w' => $vtx->getX() * $this->_matrix[12] + $vtx->getY() * $this->_matrix[13] + $vtx->getZ() * $this->_matrix[14] + $vtx->getW() * $this->_matrix[15],
            'color' => $vtx->getColor() ));
    }
}
?>