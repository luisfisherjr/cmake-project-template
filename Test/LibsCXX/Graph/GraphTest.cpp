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

TEST_F(GraphSearchTest, TestFileGraphConstructors) {

//    std::ifstream infile(graphFile1);
    std::ifstream infile(graphFile1);

//    std::cout << std::endl << graphFile1 << std::endl;

    graph = graphFactory->createGraph(ADJACENCY_LIST, infile);
    allGraphs.push_back(graph);
//    std::cerr << "end of " << graphFile1 << " reached..." << std::endl;

    infile.clear() ;
    infile.seekg(0, infile.beg) ;

    graph = graphFactory->createGraph(ADJACENCY_MATRIX, infile);
    allGraphs.push_back(graph);
//    std::cerr << "end of " << graphFile1 << " reached..." << std::endl;

    infile.clear() ;
    infile.seekg(0, infile.beg) ;

    graph = graphFactory->createGraph(OBJECT_ORIENTED, infile);
    allGraphs.push_back(graph);
//    std::cerr << "end of " << graphFile1 << " reached..." << std::endl;

    infile.close();

    EXPECT_TRUE(allGraphs.size() == 3);
};