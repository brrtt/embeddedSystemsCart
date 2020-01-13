//J Barrett Chesebrough
//macros.h
//all macro definitions

//utility
#define CLEAN           (0x00) //for clearing registers

//Port 1
#define P1_0_LED1       (0x01) // P1_0
#define P1_0_LED2       (0x02) // P1_1
#define V_THUMB         (0x04) // P1_2
#define TEST_PROBE      (0x08) // P1_3
#define V_DETECT_R      (0x10) // P1_4
#define V_DETECT_L      (0x20) // P1_5
#define SD_MOSI         (0x40) // P1_6
#define SD_MISO         (0x80) // P1_7

//Port 2
#define BCLUART_TXD     (0x01) // P2_0
#define BCLUART_RXD     (0x02) // P2_1
#define SD_SPICLK       (0x04) // P2_2
#define P2_3            (0x08) // P2_3
#define P2_4            (0x10) // P2_4
#define J4_34           (0x20) // P2_5
#define J4_35           (0x40) // P2_6
#define P2_7            (0x80) // P2_7

//Port 3
#define J3_23           (0x01) // P3_0
#define J3_24           (0x02) // P3_1
#define J3_25           (0x04) // P3_2
#define J3_26           (0x08) // P3_3
#define L_REVERSE       (0x10) // P3_4   
#define L_FORWARD       (0x20) // P3_5  
#define R_REVERSE       (0x40) // P3_6   
#define R_FORWARD       (0x80) // P3_7   

//Port 4
#define SD_CS           (0x01) // P4_0
#define J4_31           (0x02) // P4_1
#define J4_32           (0x04) // P4_2
#define J4_33           (0x08) // P4_3
#define UCB1_CS_LCD     (0x10) // P4_4
#define P4_4            (0x20) // P4_5
#define P4_5            (0x40) // P4_6
#define J3_29           (0x80) // P4_7

//Port 5
#define UCB1SIMO        (0x01) // P5_0
#define UCB1SOMI        (0x02) // P5_1
#define UCB1SCK         (0x04) // P5_2
#define RESET_LCD       (0x08) // P5_3
#define P5_4            (0x10) // P5_4
#define SW2             (0x20) // 5.5 Switch 1
#define SW1             (0x40) // 5.6 Switch 2
#define LCD_BACKLITE    (0x80) // P5_7

//Port 6
#define UCA3TXD         (0x01) // P6_0
#define UCA3RXD         (0x02) // P6_1
#define J1_5            (0x04) // P6_2
#define MAG_INT         (0x08) // P6_3
#define P6_4            (0x10) // P6_4
#define P6_5            (0x20) // P6_5
#define P6_6            (0x40) // P6_6
#define P6_7            (0x80) // P6_7

//Port 7
#define I2CSDA          (0x01) // P7_0
#define I2CSCL          (0x02) // P7_1
#define SD_DETECT       (0x04) // P7_2
#define J4_36           (0x08) // P7_3
#define P7_4            (0x10) // P7_4
#define P7_5            (0x20) // P7_5
#define P7_6            (0x40) // P7_6
#define P7_7            (0x80) // P7_7

//Port 8
#define IR_LED          (0x01) // P8_0
#define OPT_INT         (0x02) // P8_1
#define TMP_INT         (0x04) // P8_2
#define INT2            (0x08) // P8_3

//Port J
#define PJ_0            (0x01) // PJ_0
#define PJ_1            (0x02) // PJ_1
#define PJ_2            (0x04) // PJ_2
#define PJ_3            (0x08) // PJ_3
#define LFXIN           (0x10) // PJ_4
#define LFXOUT          (0x20) // PJ_5
#define HFXIN           (0x40) // PJ_6
#define HFXOUT          (0x80) // PJ_7

//from main.c
#define RESET_STATE             (0)
#define ALWAYS                  (1)
#define ORIGINAL             (0x00) //
#define RED_LED              (0x01) // RED LED 0
#define GRN_LED              (0x02) // GREEN LED 1
#define SW2                  (0x20) // 5.5 Switch 1
#define SW1                  (0x40) // 5.6 Switch 2

//Movement States
#define NONE ('N')
#define STRAIGHT ('L')
#define CIRCLE ('C')
#define TRIANGLE ('T')
#define WAIT ('W')
#define START ('S')
#define RUN ('R')
#define END ('E')

// run_case
#define WHEEL_COUNT_TIME (10)
#define RIGHT_COUNT_TIME (7)
#define LEFT_COUNT_TIME (8)
#define TRAVEL_DISTANCE (10)
#define WAITING2START (50)

//run_circle_case
#define RIGHT_COUNT_TIME_CIRCLE (10)
#define LEFT_COUNT_TIME_CIRCLE  (2)
#define TRAVEL_DISTANCE_CIRCLE (49)
#define TRAVEL_DISTANCE_CIRCLEa (48)

//run_triangle_case
#define RIGHT_COUNT_TIME_TRIANGLE  (4)
#define RIGHT_COUNT_TIME_TRIANGLEa (10)
#define LEFT_COUNT_TIME_TRIANGLE  (0)
#define TRAVEL_DISTANCE_TRIANGLE (10)
#define TRAVEL_DISTANCE_TRIANGLEa (10)
#define TRAVEL_DISTANCE_LEG1 (16)
#define TRAVEL_DISTANCE_TRIANGLE1 (23)
#define TRAVEL_DISTANCE_LEG2 (30)
#define TRAVEL_DISTANCE_TRIANGLE2 (37)
#define TRAVEL_DISTANCE_LEG3 (44)


