/* 
 * This script file corresponding to config.java
 * and open the template in the editor.
 */
screenSize= {};
screenSize.width = 448;
screenSize.height = 733;
window.oriImg= "images/hair.png"; 
window.face ='images/guo4.jpg';


//here we config the face position

 facex = 78;
 facey = 65;




var imgWidth = screenSize.width;
var imgHeight = screenSize.height; 

window.imgWidth = screenSize.width;
window.imgHeight = screenSize.height;







Config = new Object();
Config.alpha = 1.0;
Config.gridLength = 20;
Config.imageDeformation = new Object();
Config.binlinearInterpolation = new Object();
Config.eps = 0.00001;





window.p = new Array();
pLength = 0;
window.qbak = new Array();
 


window.g = new Array();
window.gTrans = new Array();



for ( i = 0; i < imgWidth ; i += Config.gridLength ) {
    for ( j = 0; j < imgHeight ; j += Config.gridLength ) {
       a = new Point(i,j);
       b = new Point(i + Config.gridLength, j);
       c = new Point(i + Config.gridLength, j + Config.gridLength);
       d = new Point(i, j + Config.gridLength);
       window.g[window.g.length]= new Grid(a,b,c,d);
    }
}
 
Util = new Util();