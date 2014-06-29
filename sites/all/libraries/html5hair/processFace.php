<?php session_start(); 

if (isset($_SESSION['face'])) {
   echo $_SESSION['face'];
}

?>