<?php 

class SavePass{
    private $file;
    function __construct() {
        $a = func_get_args(); 
        $i = func_num_args(); 
        if (method_exists($this,$f='__construct'.$i)) { 
            call_user_func_array(array($this,$f),$a); 
        }
    }

    function __construct1($_file) 
    { 
        $this->file = $_file;
    }
    
    public function get_password($username){
        
        if (($f = fopen($this->file, "r")) !== FALSE) {
            $trobades = 0;
            //$linia = fgetcsv($f, 100, ":");
            while (($linia = fgetcsv($f, 100, ":")) !== FALSE){
                if($linia != null && $linia[1]==$username){
                   printf("\nNom: %s User: %s Pass: %s",$linia[0],$linia[1],$linia[2]);
                    $trobades++;
                }
            } 
            printf("\nTotal rows %d",$trobades);
            fclose($f);
        }else{
            printf("\nNo s'ha pogut obrir %s",$this->file);
        }
        
    }

    public function list_usernames(){
        
        if (($f = fopen($this->file, "r")) !== FALSE) {
            $trobades = 0;
            //$linia = fgetcsv($f, 100, ":");
            while (($linia = fgetcsv($f, 100, ":")) !== FALSE){
                printf("\nNom: %s User: %s Pass: %s",$linia[0],$linia[1],$linia[2]);
                $trobades++;
            }
            printf("\nTotal rows %d",$trobades);
            fclose($f);
        }else{
            printf("\nNo s'ha pogut obrir %s",$this->file);
        }
    }

    public function add_password($nom,$user,$pwd)
    {
        if (($f = fopen($this->file, "a")) !== FALSE) {
            $params = [$nom,$user,$pwd];
            fputcsv($f,$params,':');
            fclose($f);
        }else{
            printf("\nNo s'ha pogut obrir %s",$this->file);
        }
    }
}

$manager = new SavePass('passwords.csv');
$manager->add_password('Mila ftp','alumne','alumne');
$manager->get_password('alumne');
$manager->list_usernames();

?>