#include "src/lib/trojanmap.h"

#include <map>
#include <vector>

#include "gtest/gtest.h"

TEST(TrojanMapTest, Autocomplete) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  auto names = m.Autocomplete("");
  std::vector<std::string> gt1 = {};
  EXPECT_EQ(names, gt1);
  names = m.Autocomplete("c");
  std::vector<std::string> gt2 = { "Crosswalk1", "CVS", "Community of Christ", "Carson Center", "ChickfilA", "Coffee Bean1", "Cava", "Century Apartments 1", "CorePower Yoga", "Century 2", "Cardinal Gardens", "Cal Mart Beer 38 Wine Food Store", "Coffee Bean2", "Car Pooling station", "crosswalk3", "Crosswalk2", "Chipotle Mexican Grill" };
  EXPECT_EQ(names, gt2);
  names = m.Autocomplete("ci");
  std::vector<std::string> gt3 = {};
  EXPECT_EQ(names, gt3);
}

TEST(TrojanMapTest, FindPosition) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  auto position = m.GetPosition("");
  std::pair<double, double> gt1(-1, -1);
  EXPECT_EQ(position, gt1);
  position = m.GetPosition("ralphs");
  std::pair<double, double> gt2(-1, -1);
  EXPECT_EQ(position, gt2);
  position = m.GetPosition("JeffersonUSC");
  std::pair<double, double> gt3(34.0224012, -118.2779241);
  EXPECT_EQ(position, gt3);
}

TEST(TrojanMapTest, CalculateShortestPath) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();
  auto path = m.CalculateShortestPath("Ralphs", "chickfilA");
  std::vector<std::string> gt{};
  std::cout << "My path length: "  << m.CalculatePathLength(path) << "miles" << std::endl;
  std::cout << "GT path length: " << m.CalculatePathLength(gt) << "miles" << std::endl;
  EXPECT_EQ(path, gt);
}
