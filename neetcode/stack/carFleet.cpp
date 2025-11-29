// There are n cars traveling to the same destination on a one-lane highway.

// You are given two arrays of integers position and speed, both of length n.
// - position[i] is the position of the ith car (in miles)
// - speed[i] is the speed of the ith car (in miles per hour)

// The destination is at position target miles.

// A car can not pass another car ahead of it. It can only catch up to another car and
//  then drive at the same speed as the car ahead of it.

// A car fleet is a non-empty set of cars driving at the same position and same speed.
// A single car is also considered a car fleet.

//  If a car catches up to a car fleet the moment the fleet reaches the destination,
// then the car is considered to be part of the fleet.

// Return the number of different car fleets that will arrive at the destination.
// You should aim for a solution with O(nlogn) time and O(n) space, where n is the size of the input array
#include <vector>
#include <map>
#include <stack>
class Solution
{
public:
    int carFleet(int target, std::vector<int> &position, std::vector<int> &speed)
    {
        std::map<int, int> posSpeedMap;
        std::vector<double> timeArr;
        timeArr.reserve(posSpeedMap.size());

        // t: O (n log n), s: O (n)
        for (int i = 0; i < position.size(); ++i)
        {
            posSpeedMap[position[i]] = speed[i];
        }

        // t: O (n)
        for (const auto &[pos, speed] : posSpeedMap)
        {
            double arrivalTime = (target - pos) / speed;
            timeArr.push_back(arrivalTime);
        }

        int fleet = position.size(); // maximum number of fleet

        std::stack<double> fleetStack;

        fleetStack.push(timeArr[position.size() - 1]); // earliest the first fleet will arrive

        for (int i = position.size() - 2; i >= 0; --i)
        {

            if (timeArr[i] <= fleetStack.top())
            {
                fleet--;
            }
            else
            {
                fleetStack.push(timeArr[i]);
            }
        }
        return fleet;
    }
};
