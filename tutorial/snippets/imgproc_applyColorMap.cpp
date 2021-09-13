/*
 * @Description:  
 * @Author: ren qian
 * @Date: 2021-09-09 13:11:15
 */
/*
 * @Description:  
 * @Author: ren qian
 * @Date: 2021-09-09 13:11:15
 */
/*
 * @Description:  
 * @Author: ren qian
 * @Date: 2021-09-09 13:11:15
 */
/*
 * @Description:  
 * @Author: ren qian
 * @Date: 2021-09-09 13:11:15
 */
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

#include <iostream>
using namespace std;

int main(int argc, const char *argv[]) {
  // We need an input image. (can be grayscale or color)
  if (argc < 2) {
    cerr << "We need an image to process here. Please run: colorMap "
            "[path_to_image]"
         << endl;
    return -1;
  }
  Mat img_in = imread(argv[1]);
  if (img_in.empty()) {
    cerr << "Sample image (" << argv[1]
         << ") is empty. Please adjust your path, so it points to a valid "
            "input image!"
         << endl;
    return -1;
  }
  // Holds the colormap version of the image:
  Mat img_color;
  // Apply the colormap:
  applyColorMap(img_in, img_color, COLORMAP_JET);
  // Show the result:
  imshow("colorMap", img_color);
  waitKey(0);
  return 0;
}
