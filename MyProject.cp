#line 1 "C:/Users/V/Desktop/Button/MyProject.c"
#line 26 "C:/Users/V/Desktop/Button/MyProject.c"
bit oldstate;

void main() {

 DDB0_bit = 0;
 DDRC = 0xFF;
 PORTC = 0xAA;

 oldstate = 0;



 while(1)
 {
 PORTC = ~PORTC;
 oldstate = 0;
 }
}
