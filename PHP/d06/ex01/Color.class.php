<?php
Class Color
{
	public static $verbose = false;
	public static function doc()
	{
		return file_get_contents('Color.doc.txt');
	}
	
	public $red;
	public $green;
	public $blue;

	public function __construct(array $args)
	{
		if (array_key_exists('rgb', $args))
		{
			$this->red = intval($args['rgb']) >> 16;
			$this->green = (intval($args['rgb']) >> 8) & 0xFF;
			$this->blue = intval($args['rgb']) & 0xFF;
		}
		else
		{
			$this->red = (array_key_exists('red', $args) ? intval($args['red']) : 0);
			$this->green = array_key_exists('green', $args) ? intval($args['green']) : 0;
			$this->blue = array_key_exists('blue', $args) ? intval($args['blue']) : 0;
		}
		if (self::$verbose)
			printf("%s constructed.\n", $this);
		return;
	}

	public function __destruct()
	{
		if (self::$verbose)
			printf("%s destructed.\n", $this);
	}

	public function __toString()
	{
		return sprintf("Color( red: %3d, green: %3d, blue: %3d )", $this->red, $this->green, $this->blue);
	}

	public function add(Color $rhs)
	{
		return new Color(array('red' => $this->red + $rhs->red, 'green' => $this->green + $rhs->green, 'blue' => $this->blue + $rhs->blue));
	}

	public function sub(Color $rhs)
	{
		return new Color(array('red' => $this->red - $rhs->red, 'green' => $this->green - $rhs->green, 'blue' => $this->blue - $rhs->blue));
	}

	public function mult($f)
	{
		return new Color(array('red' => $this->red * $f, 'green' => $this->green * $f, 'blue' => $this->blue * $f));
	}
}
?>