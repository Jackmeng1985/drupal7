// configuration

/* 
 * This script file corresponding to config.java
 * and open the template in the editor.
 */
 
window.faceImg = new Array();  
window.hairImg = new Array();
window.p = new Array();
pLength = 0;
window.qbak = new Array();

window.g = new Array();
window.gTrans = new Array();

function initializePoints(){  
  var i = 0;
  j =  hair_points.length;

  for(i=0;i<j; i++){
    q = new Point(hair_points[i].x, hair_points[i].y); 
    window.p[window.p.length] = q; // add the point to the array of preset points.
  }   
 }

Config = new Object();
Config.alpha = 1.0;
Config.gridLength = 10;
Config.imageDeformation = new Object();
Config.binlinearInterpolation = new Object();
Config.eps = 0.00001;


window.g = new Array();
window.gTrans = new Array();

Util = new Util();


window.canvasw = hair_width;
window.canvash = hair_height;


        





for ( i = 0; i < window.canvasw ; i += Config.gridLength ) {
    for ( j = 0; j < window.canvash ; j += Config.gridLength ) {
       a = new Point(i,j);
       b = new Point(i + Config.gridLength, j);
       c = new Point(i + Config.gridLength, j + Config.gridLength);
       d = new Point(i, j + Config.gridLength);
       window.g[window.g.length]= new Grid(a,b,c,d);
    }
}
 
