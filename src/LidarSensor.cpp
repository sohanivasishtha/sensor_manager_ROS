#include "LidarSensor.h"
#include <cmath>
using namespace std;
#include <limits>
#include <rclcpp/rclcpp.hpp>


LidarSensor::LidarSensor(){}
LidarSensor::LidarSensor(int val_id, string val_name){
    id = val_id;
    name = val_name;
}
LidarSensor::~LidarSensor(){}



void LidarSensor::readValue() {
    cout << "The reading is from " << name << "sensor  having Id:" <<id<< endl;
}

bool LidarSensor::validateReading(float value){
    if (value > 0 && value < 100){
                cout << "Valid reading"<< endl;
                return true;
            }
            cout <<" Invalid reading" << endl;
            return false;
}

std::optional<sensor_manager_ros::msg::LidarSummary> LidarSensor::addSummaryFromScan(const std::vector<float>& ranges, double timestamp){
    
    if(ranges.empty()) return std::nullopt;

    sensor_manager_ros::msg::LidarSummary summary;


    float min_val = std::numeric_limits<float>::max();
    float max_val = -std::numeric_limits<float>::max();
    double sum = 0;
    int count = 0;
    double variance_sum = 0;
    int N = 30;
        for (float r: ranges){
        if (isinf(r) || isnan(r)) continue;
        
        if( r < min_val) min_val = r;
        if( r > max_val) max_val = r;

        sum += r;

        count++;

    }
    if (count == 0) return std::nullopt;

    double mean = sum/ count;


    for (float r: ranges){
        if (isnan(r) || isinf(r)) continue;
        
        variance_sum += (r -  mean) * (r - mean);

    }
    double std_dev = std::sqrt(variance_sum / count);


    // Calculate entropy:
    float bin_width = (max_val - min_val)/ N;
    if (bin_width == 0) bin_width = 1e-6;
    vector<int> bracket(N, 0);
    for (float r : ranges){
        if (std::isnan(r) || std::isinf(r)) continue;
        int bin_idx = std::floor((r - min_val) / bin_width);
        if (bin_idx >= N) bin_idx = N - 1;
        //Creates Histogram
        bracket[bin_idx] += 1 ;  
    }
    double H = 0;
    // Convert to probablities
    for (int bin : bracket){
        double prob = static_cast<double> (bin) / count;
        if (prob > 0){
            H += -1*prob * log (prob);
        }
        
    }
    // Push back all the results into summary
    summary.timestamp = timestamp;
    summary.min_distance = min_val;
    summary.max_distance = max_val;
    summary.std_dev = std_dev;
    summary.entropy = H;
    

    /*RCLCPP_INFO(rclcpp::get_logger("LidarSensor"),
    "Summary -> timestamp: %.2f | min: %.3f | max: %.3f | std_dev: %.3f | entropy: %.3f",
    summary.timestamp, summary.min_distance, summary.max_distance, summary.std_dev, summary.entropy );
      */
     
    return summary;

}
