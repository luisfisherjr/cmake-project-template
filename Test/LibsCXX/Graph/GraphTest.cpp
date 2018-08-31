//include to be tested
#include "Graph.hpp"
#include "GraphTest.hpp"

//using ::testing::Return;

GraphSearchTest::GraphSearchTest() {
    graphFactory = new GraphFactory();
};

GraphSearchTest::~GraphSearchTest() {
    delete graphFactory;
    allGraphs.clear();
};

void GraphSearchTest::SetUp() {


};
void GraphSearchTest::TearDown() {

//    destroyDoubleLinkedList(doubleLinkedList);
};


TEST_F(GraphSearchTest, TestDefualtGraphConstructors) {

    graph = graphFactory->createGraph(ADJACENCY_LIST);
    allGraphs.push_back(graph);

    graph = graphFactory->createGraph(ADJACENCY_MATRIX);
    allGraphs.push_back(graph);

    graph = graphFactory->createGraph(OBJECT_ORIENTED);
    allGraphs.push_back(graph);

    EXPECT_TRUE(allGraphs.size() == 3);
};