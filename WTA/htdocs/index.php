<html>
  <head>
    <title>
      Title 
    </title>
    <link rel="stylesheet" href="theme.css"/>
  </head>

  <body> 
	
    <div class="container">
      <div class="heading">
        <h2> Local Web Server </h2>
      </div>
      <h3> Problem 1 </h3>
      <ul>
        <?php 
          for ($x = 0; $x <= 10; $x++) 
          {
            $y = rand(10,100);
        	  echo ("<li> The number is $y, it's square is ". pow($y,2) . " and it's cube is " . pow($y, 3) ."  </li>");
          }
        ?>
      </ul>
      <h3> Problem 2 </h3>
      <ul>
        <?php 
          function printArr($arr){
            for($x = 0; $x < count($arr); $x++)
            {
              echo "$arr[$x] ";
            }  
          }

          
          $animals = array("Dogs" , "Cats" , "Monkeys" , "Squirrels");
          echo " The array is : ";
          echo (implode(" ",$animals));
          
          echo ("<li> Count of array : " . count($animals) . "</li>");
          echo ("<li> Flip of array : " . implode(" ",array_flip($animals)) . "</li>");
          echo ("<li> Search of \"Monkeys\" in array : " . array_search("Monkeys" , $animals ) . "</li>");
          echo ("<li> Search of \"Donkeys\" in array : " . array_search("Donkeys" , $animals ) . "</li>");
          echo ("<li> Key_Exist of \"2\" in array : " . array_key_exists(2 , $animals ) . "</li>");
          echo ("<li> Key_Exist of \"5\" in array : " . array_key_exists(5 , $animals ) . "</li>");
          echo ("<li> Size of  array : " . sizeof($animals ) . "</li>");sort($animals);
          echo ("<li> Sorted array : ". implode(" ",$animals) . "</li>");
        ?>
      </ul>
      <h3> Problem 3 </h3>
      <ul>
        <?php
          $string="racecar";
          echo("<li> The string is $string </li>");
          echo("<li> The reversed string is ". strrev($string) . "</li>");
          echo("<li> Is it a palidrome  : " . ($string == strrev($string)) . "</li>");
        ?>
      </ul>
    </div>
  </body>
</html>

