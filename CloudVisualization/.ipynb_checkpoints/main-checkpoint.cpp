#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/visualization/pcl_visualizer.h>


pcl::PointCloud<pcl::PointXYZ> readPCD(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    int count = 0;
    bool data_section = false;
    while (std::getline(file, line)) {
        if (line.find("WIDTH") != std::string::npos) {
            std::istringstream iss(line);
            std::string width_str;
            iss >> width_str >> count;
        }
        if (line == "DATA ascii") {
            data_section = true;
            break;
        }
    }
    pcl::PointCloud<pcl::PointXYZ> cloud;
    cloud.width = count;
    cloud.height = 1;
    cloud.is_dense = false;
    cloud.resize(cloud.width * cloud.height);
    int index = 0;
    while (data_section && std::getline(file, line) && index < count) {
        std::istringstream iss(line);
        float x, y, z;
        if (iss >> x >> y >> z) {
            cloud.points[index].x = x;
            cloud.points[index].y = y;
            cloud.points[index].z = z;
            index++;
        }
    }

    file.close();
    std::cout << "Количество точек в облаке: " << cloud.size() << std::endl;
    return cloud;
}

int main() {
    pcl::PointCloud<pcl::PointXYZ> cloud1 = readPCD("../clouds/cloud_9.pcd");
    pcl::PointCloud<pcl::PointXYZ> cloud2 = readPCD("../clouds/cloud_12.pcd");
    pcl::PointCloud<pcl::PointXYZ> cloud3 = readPCD("../clouds/cloud_13.pcd");
    pcl::PointCloud<pcl::PointXYZ> cloud4 = readPCD("../clouds/cloud_17.pcd");
    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;


    return 0;
}
