 <?php
        // Do make a visitors.txt file and set permission to 0777

        $ip = $_SERVER['REMOTE_ADDR'];
        $browser = $_SERVER['HTTP_USER_AGENT'];
        $dateTime = date('Y/m/d G:i:s');
        $file = "visitors.txt";
        $file = fopen($file, "a");
        $data = "$ip\n";
        fwrite($file, $data);
        fclose($file);
?>