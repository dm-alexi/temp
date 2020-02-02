<?php
require_once 'Triangle.class.php';
class Render
{
    public static $verbose = false;
	public static function doc()
	{
		return file_get_contents('Render.doc.txt');
    }

    const VERTEX = "VERTEX";
    const EDGE = "EDGE";
    const RASTERIZE = "RASTERIZE";

    private $_width;    
    private $_height;
    private $_filename;
    private $_image;

    public function getWidth() { return $this->_width; }
    public function getHeight() { return $this->_height; }
    public function getFilename() { return $this->_filename; }
    public function getImage() { return $this->_image; }
    
    public function __construct($width, $height, $filename)
    {
        $this->_width = $width;
        $this->_height = $height;
        $this->_filename = $filename;
        $this->_image = imagecreatetruecolor($this->getWidth(), $this->getHeight());
        imagecolorallocate($this->_image, 0, 0, 0);
        if (self::$verbose)
            echo "Render instance constructed\n";
    }
    
    public function __destruct()
	{
		if (self::$verbose)
            echo "Render instance destructed\n";
        return;
	}
	
    public function __toString()
	{
        return "Render";
    }

    public function renderVertex(Vertex $screenVertex)
    {
        $color = imagecolorallocate($this->getImage(), $screenVertex->getColor()->red, $screenVertex->getColor()->green, $screenVertex->getColor()->blue);
        imagesetpixel($this->getImage(), $screenVertex->getX() + $this->getWidth() / 2, $screenVertex->gety() + $this->getHeight() / 2, $color);
    }

    public function renderEdge(Vertex $a, Vertex $b)
    {
        $color1 = imagecolorallocate($this->getImage(), $a->getColor()->red, $a->getColor()->green, $a->getColor()->blue);
        $color2 = imagecolorallocate($this->getImage(), $b->getColor()->red, $b->getColor()->green, $b->getColor()->blue);
        imagesetstyle($this->getImage(), array($color1, $color2));
        imageline($this->getImage(), $a->getX() + $this->getWidth() / 2, $a->getY() + $this->getHeight() / 2, $b->getX() + $this->getWidth() / 2, $b->getY() + $this->getHeight() / 2, IMG_COLOR_STYLED);
    }

    public function renderTriangle(Triangle $triangle, $mode)
    {
        switch($mode)
        {
            case self::VERTEX:
                foreach ($triangle->getDots() as $dot)
                    $this->renderVertex($dot);
                break;
            case self::EDGE:
                $this->renderEdge($triangle->getA(), $triangle->getB());
                $this->renderEdge($triangle->getB(), $triangle->getC());
                $this->renderEdge($triangle->getC(), $triangle->getA());
                break;
        }
    }

    public function renderMesh($mesh, $mode)
    {
        foreach ($mesh as $key => $val)
            //foreach ($val as $triangle)    
                $this->renderTriangle($val, $mode);
    }

    public function develop()
    {
        imagepng($this->getImage(), $this->getFilename());
    }
}