#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include <boost/filesystem.hpp>
#include "efsw/efsw.hpp"

class Image : public efsw::FileWatchListener {
public:
    explicit Image(std::string filename);

    void display() {
        cv::Mat image;
        image = cv::imread(path_.c_str());

        if (!image.data) {
            std::cout << "Could not open or find the image" << std::endl;
            return;
        }

        // FIXME: make the window redisplay in the right place
        namedWindow("Display window", cv::WINDOW_AUTOSIZE);
        imshow("Display window", image);
    }

    void show() {
        watcher_->addWatch(path_.parent_path().string(), this, false);
        this->display();
    }

    // FIXME: clean up the lint warning
    void
    handleFileAction(efsw::WatchID watchid, const std::string &dir, const std::string &filename, efsw::Action action,
                     std::string oldFilename = "") override {
        if (filename == path_.filename()) {
            std::cout << "DIR (" << dir << ") FILE (" << filename << ") has event " << action << std::endl;
            this->display();
        }
    }

private:
    boost::filesystem::path path_;
    std::unique_ptr<efsw::FileWatcher> watcher_;
};

Image::Image(std::string filename) {
    path_ = boost::filesystem::path(filename);
    watcher_ = std::make_unique<efsw::FileWatcher>();
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << " Usage: display_image directory imageImageToLoadAndDisplay" << std::endl;
        return -1;
    }
    auto i = Image(argv[1]);
    i.show();
    cv::waitKey(0);

    return 0;
}