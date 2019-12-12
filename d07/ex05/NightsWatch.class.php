<?php
class NightsWatch
{
    private $watchers = array();
    
    public function recruit($person)
    {
        $this->watchers[] = $person;
    }

    public function fight()
    {
        foreach ($this->watchers as $person)
            if ($person instanceof Ifighter)
                $person->fight();
    }
}
?>