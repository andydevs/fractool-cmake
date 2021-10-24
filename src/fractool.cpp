#include <iostream>
#include <opencv2/opencv.hpp>

#define RED_CHAN 0
#define GRN_CHAN 1
#define BLU_CHAN 2
#define NUM_CHANS 3

#define ARRAY2D(w, x, y) y*w + x
#define IMAGE(w, x, y, c) (ARRAY2D(w, x, y))*NUM_CHANS + c

const uchar COLORMAP[256][3] = {
    {255,   0,   0},
    {254,   0,   1},
    {253,   0,   2},
    {252,   0,   3},
    {251,   0,   4},
    {250,   0,   5},
    {249,   0,   6},
    {248,   0,   7},
    {247,   0,   8},
    {246,   0,   9},
    {245,   0,  10},
    {244,   0,  11},
    {243,   0,  12},
    {242,   0,  13},
    {241,   0,  14},
    {240,   0,  15},
    {239,   0,  16},
    {238,   0,  17},
    {237,   0,  18},
    {236,   0,  19},
    {235,   0,  20},
    {234,   0,  21},
    {233,   0,  22},
    {232,   0,  23},
    {231,   0,  24},
    {230,   0,  25},
    {229,   0,  26},
    {228,   0,  27},
    {227,   0,  28},
    {226,   0,  29},
    {225,   0,  30},
    {224,   0,  31},
    {223,   0,  32},
    {222,   0,  33},
    {221,   0,  34},
    {220,   0,  35},
    {219,   0,  36},
    {218,   0,  37},
    {217,   0,  38},
    {216,   0,  39},
    {215,   0,  40},
    {214,   0,  41},
    {213,   0,  42},
    {212,   0,  43},
    {211,   0,  44},
    {210,   0,  45},
    {209,   0,  46},
    {208,   0,  47},
    {207,   0,  48},
    {206,   0,  49},
    {205,   0,  50},
    {204,   0,  51},
    {203,   0,  52},
    {202,   0,  53},
    {201,   0,  54},
    {200,   0,  55},
    {199,   0,  56},
    {198,   0,  57},
    {197,   0,  58},
    {196,   0,  59},
    {195,   0,  60},
    {194,   0,  61},
    {193,   0,  62},
    {192,   0,  63},
    {191,   0,  64},
    {190,   0,  65},
    {189,   0,  66},
    {188,   0,  67},
    {187,   0,  68},
    {186,   0,  69},
    {185,   0,  70},
    {184,   0,  71},
    {183,   0,  72},
    {182,   0,  73},
    {181,   0,  74},
    {180,   0,  75},
    {179,   0,  76},
    {178,   0,  77},
    {177,   0,  78},
    {176,   0,  79},
    {175,   0,  80},
    {174,   0,  81},
    {173,   0,  82},
    {172,   0,  83},
    {171,   0,  84},
    {170,   0,  85},
    {169,   0,  86},
    {168,   0,  87},
    {167,   0,  88},
    {166,   0,  89},
    {165,   0,  90},
    {164,   0,  91},
    {163,   0,  92},
    {162,   0,  93},
    {161,   0,  94},
    {160,   0,  95},
    {159,   0,  96},
    {158,   0,  97},
    {157,   0,  98},
    {156,   0,  99},
    {155,   0, 100},
    {154,   0, 101},
    {153,   0, 102},
    {152,   0, 103},
    {151,   0, 104},
    {150,   0, 105},
    {149,   0, 106},
    {148,   0, 107},
    {147,   0, 108},
    {146,   0, 109},
    {145,   0, 110},
    {144,   0, 111},
    {143,   0, 112},
    {142,   0, 113},
    {141,   0, 114},
    {140,   0, 115},
    {139,   0, 116},
    {138,   0, 117},
    {137,   0, 118},
    {136,   0, 119},
    {135,   0, 120},
    {134,   0, 121},
    {133,   0, 122},
    {132,   0, 123},
    {131,   0, 124},
    {130,   0, 125},
    {129,   0, 126},
    {128,   0, 127},
    {127,   0, 128},
    {126,   0, 129},
    {125,   0, 130},
    {124,   0, 131},
    {123,   0, 132},
    {122,   0, 133},
    {121,   0, 134},
    {120,   0, 135},
    {119,   0, 136},
    {118,   0, 137},
    {117,   0, 138},
    {116,   0, 139},
    {115,   0, 140},
    {114,   0, 141},
    {113,   0, 142},
    {112,   0, 143},
    {111,   0, 144},
    {110,   0, 145},
    {109,   0, 146},
    {108,   0, 147},
    {107,   0, 148},
    {106,   0, 149},
    {105,   0, 150},
    {104,   0, 151},
    {103,   0, 152},
    {102,   0, 153},
    {101,   0, 154},
    {100,   0, 155},
    { 99,   0, 156},
    { 98,   0, 157},
    { 97,   0, 158},
    { 96,   0, 159},
    { 95,   0, 160},
    { 94,   0, 161},
    { 93,   0, 162},
    { 92,   0, 163},
    { 91,   0, 164},
    { 90,   0, 165},
    { 89,   0, 166},
    { 88,   0, 167},
    { 87,   0, 168},
    { 86,   0, 169},
    { 85,   0, 170},
    { 84,   0, 171},
    { 83,   0, 172},
    { 82,   0, 173},
    { 81,   0, 174},
    { 80,   0, 175},
    { 79,   0, 176},
    { 78,   0, 177},
    { 77,   0, 178},
    { 76,   0, 179},
    { 75,   0, 180},
    { 74,   0, 181},
    { 73,   0, 182},
    { 72,   0, 183},
    { 71,   0, 184},
    { 70,   0, 185},
    { 69,   0, 186},
    { 68,   0, 187},
    { 67,   0, 188},
    { 66,   0, 189},
    { 65,   0, 190},
    { 64,   0, 191},
    { 63,   0, 192},
    { 62,   0, 193},
    { 61,   0, 194},
    { 60,   0, 195},
    { 59,   0, 196},
    { 58,   0, 197},
    { 57,   0, 198},
    { 56,   0, 199},
    { 55,   0, 200},
    { 54,   0, 201},
    { 53,   0, 202},
    { 52,   0, 203},
    { 51,   0, 204},
    { 50,   0, 205},
    { 49,   0, 206},
    { 48,   0, 207},
    { 47,   0, 208},
    { 46,   0, 209},
    { 45,   0, 210},
    { 44,   0, 211},
    { 43,   0, 212},
    { 42,   0, 213},
    { 41,   0, 214},
    { 40,   0, 215},
    { 39,   0, 216},
    { 38,   0, 217},
    { 37,   0, 218},
    { 36,   0, 219},
    { 35,   0, 220},
    { 34,   0, 221},
    { 33,   0, 222},
    { 32,   0, 223},
    { 31,   0, 224},
    { 30,   0, 225},
    { 29,   0, 226},
    { 28,   0, 227},
    { 27,   0, 228},
    { 26,   0, 229},
    { 25,   0, 230},
    { 24,   0, 231},
    { 23,   0, 232},
    { 22,   0, 233},
    { 21,   0, 234},
    { 20,   0, 235},
    { 19,   0, 236},
    { 18,   0, 237},
    { 17,   0, 238},
    { 16,   0, 239},
    { 15,   0, 240},
    { 14,   0, 241},
    { 13,   0, 242},
    { 12,   0, 243},
    { 11,   0, 244},
    { 10,   0, 245},
    {  9,   0, 246},
    {  8,   0, 247},
    {  7,   0, 248},
    {  6,   0, 249},
    {  5,   0, 250},
    {  4,   0, 251},
    {  3,   0, 252},
    {  2,   0, 253},
    {  1,   0, 254},
    {  0,   0, 255}
};

int main(int argc, char **argv) {
    // Image parameters
    const unsigned size_x = 600;
    const unsigned size_y = 400;

    // Resources
    uchar* param_buffer = new uchar[size_x * size_y];
    uchar* color_buffer = new uchar[size_x * size_y * NUM_CHANS];

    // FRACTAL:
    // Run iteration algorithm
    uchar n;
    for (unsigned j = 0; j < size_y; ++j) {
        for (unsigned i = 0; i < size_x; ++i) {
            // Parameter
            n = 255 * (i + j) / (size_x + size_y);
            
            // Set parameter
            param_buffer[ARRAY2D(size_x, i, j)] = n;
        }
    }

    // COLORING:
    // Map parameter space to color space
    uchar p;
    for (unsigned j = 0; j < size_y; ++j) {
        for (unsigned i = 0; i < size_x; ++i) {
            // Get parameter
            n = param_buffer[ARRAY2D(size_x, i, j)];

            // Color image using colormap
            color_buffer[IMAGE(size_x, i, j, RED_CHAN)] = COLORMAP[n][RED_CHAN];
            color_buffer[IMAGE(size_x, i, j, GRN_CHAN)] = COLORMAP[n][GRN_CHAN];
            color_buffer[IMAGE(size_x, i, j, BLU_CHAN)] = COLORMAP[n][BLU_CHAN];
        }
    }

    // SAVE:
    // Save image
    cv::Mat image(size_y, size_x, CV_8UC3, color_buffer);
    cv::imwrite("fractal.png", image);

    // Delete resources
    delete[] param_buffer;
    delete[] color_buffer;

    // Exit
    return 0;
}