
// TEST
// TEST is used to define a simple test case.
// It does not require any setup or teardown code.
// It is suitable for tests that do not need to share common setup or state.

// TEST_F
// TEST_F is used to define a test case that uses a test fixture.
// A test fixture is a class derived from ::testing::Test that provides common
// setup and teardown code for multiple tests. It is suitable for tests that
// need to share common setup, state, or helper functions.

#include <gtest/gtest.h>

#include <sstream>

#include "../simple_svg_1.0.0.hpp"

using namespace svg;

// SVGTest
// -----------------------------------------------------------------------------------------

class SVGTest : public ::testing::Test
{
   protected:
    Layout layout;

    void SetUp() override
    {
        layout = Layout(Dimensions(100, 100),
                        Layout::TopLeft);  // default is BottomLeft
    }
};

TEST_F(SVGTest, ShapeCollTest)
{
    ShapeColl ShapeColl;
    std::string sercollStr = ShapeColl.toString(layout);

    // std::cout << "* ShapeCollTest sercollStr: " << sercollStr << std::endl;
    EXPECT_TRUE(sercollStr.empty());

    ShapeColl << Text(Point(10, 20), "Hello, SVG!", Fill(Color::Black),
                      Font(12, "Arial"));

    std::string expectedStr =
        "\t<text x=\"10\" y=\"32\" fill=\"rgb(0,0,0)\" font-size=\"12\" "
        "font-family=\"Arial\" >Hello, SVG!</text>\n";
    sercollStr = ShapeColl.toString(layout);
    // std::cout << "* ShapeCollTest sercollStr: " << sercollStr << std::endl;
    EXPECT_EQ(sercollStr, expectedStr);
}

TEST_F(SVGTest, Shape2Test)
{
    Circle circle(Point(50, 50), 20, Fill(Color::Red), Stroke(2, Color::Blue));
    std::string circleStr = circle.toString(layoutBL);

    // std::cout << "* Shape2Test circleStr: " << circleStr << std::endl;

    EXPECT_TRUE(circleStr.find("cx=\"50\"") != std::string::npos);
    EXPECT_TRUE(circleStr.find("cy=\"50\"") != std::string::npos);
    EXPECT_TRUE(circleStr.find("r=\"10\"") != std::string::npos);
    EXPECT_TRUE(circleStr.find("fill=\"rgb(255,0,0)\"") != std::string::npos);
    EXPECT_TRUE(circleStr.find("stroke=\"rgb(0,0,255)\"") != std::string::npos);
}

TEST_F(SVGTest, ShapeCollTest)
{
    ShapeColl ShapeColl;
    std::string sercollStr = ShapeColl.toString(layoutBL);

    // std::cout << "* ShapeCollTest sercollStr: " << sercollStr << std::endl;
    EXPECT_TRUE(sercollStr.empty());

    ShapeColl << Text(Point(10, 20), "Hello, SVG!", Fill(Color::Black),
                      Font(12, "Arial"));

    std::string expectedStr =
        "\t<text x=\"10\" y=\"80\" fill=\"rgb(0,0,0)\" font-size=\"12\" "
        "font-family=\"Arial\" >Hello, SVG!</text>\n";
    sercollStr = ShapeColl.toString(layoutBL);
    // std::cout << "* ShapeCollTest sercollStr: " << sercollStr << std::endl;
    EXPECT_EQ(sercollStr, expectedStr);
}

TEST_F(SVGTest, PolygonTest)
{
    Polygon polygon(Fill(Color::Green), Stroke(1, Color::Black));
    polygon << Point(0, 0) << Point(100, 0) << Point(100, 100) << Point(0, 100);
    std::string polygonStr = polygon.toString(layout);
    EXPECT_TRUE(polygonStr.find("points=\"0,0 100,0 100,100 0,100 \"") !=
                std::string::npos);
    EXPECT_TRUE(polygonStr.find("fill=\"rgb(0,128,0)\"") != std::string::npos);
    EXPECT_TRUE(polygonStr.find("stroke=\"rgb(0,0,0)\"") != std::string::npos);
}

TEST_F(SVGTest, TextTest)
{
    Text text(Point(10, 20), "Hello SVG", Fill(Color::Black),
              Font(12, "Arial"));
    std::string textStr = text.toString(layout);

    // std::cout << "TextTest textStr:\n" << textStr << std::endl;

    EXPECT_TRUE(textStr.find("x=\"10\"") != std::string::npos);
    EXPECT_TRUE(textStr.find("y=\"32\"") != std::string::npos);
    EXPECT_TRUE(textStr.find("font-size=\"12\"") != std::string::npos);
    EXPECT_TRUE(textStr.find("font-family=\"Arial\"") != std::string::npos);
    EXPECT_TRUE(textStr.find(">Hello SVG<") != std::string::npos);
}

TEST_F(SVGTest, TextRotationTest)
{
    Text text(Point(50, 50), "Rotated Text", Fill(Color::Black),
              Font(12, "Arial"), Stroke(), 45);
    std::string textStr = text.toString(layoutBL);

    // std::cout << "* TextRotationTest textStr:\n" << textStr << std::endl;

    EXPECT_TRUE(textStr.find("x=\"50\"") != std::string::npos);
    EXPECT_TRUE(textStr.find("y=\"50\"") != std::string::npos);
    EXPECT_TRUE(textStr.find("font-size=\"12\"") != std::string::npos);
    EXPECT_TRUE(textStr.find("font-family=\"Arial\"") != std::string::npos);
    EXPECT_TRUE(textStr.find("fill=\"rgb(0,0,0)\"") != std::string::npos);
    // EXPECT_TRUE(textStr.find("transform=\"rotate(45 50 50)\"") !=
    //             std::string::npos);                                  // TODO
    //             FIXME
    EXPECT_TRUE(textStr.find(">Rotated Text<") != std::string::npos);
}

TEST_F(SVGTest, LineChartTest)
{
    LineChart chart;
    Polyline line1(Stroke(1, Color::Blue));
    line1 << Point(0, 0) << Point(10, 10) << Point(20, 20);
    chart << line1;

    Polyline line2(Stroke(1, Color::Red));
    line2 << Point(0, 20) << Point(10, 10) << Point(20, 0);
    chart << line2;

    std::string chartStr = chart.toString(layoutBL);

    // std::cout << "* LineChartTest chartStr:\n" << chartStr << std::endl;

    EXPECT_TRUE(chartStr.find("stroke=\"rgb(0,0,255)\"") != std::string::npos);
    EXPECT_TRUE(chartStr.find("stroke=\"rgb(255,0,0)\"") != std::string::npos);
    EXPECT_TRUE(chartStr.find("points=\"0,0 10,10 20,20 \"") !=
                std::string::npos);
    EXPECT_TRUE(chartStr.find("points=\"0,20 10,10 20,0 \"") !=
                std::string::npos);
}

TEST_F(SVGTest, DocumentTest)
{
    Document doc("test.svg", Layout(Dimensions(200, 200)));
    doc << Circle(Point(100, 100), 50, Fill(Color::Red));
    doc << Text(Point(10, 20), "Test SVG", Fill(Color::Black));

    std::string docStr = doc.toString();

    // std::cout << "* DocumentTest docStr:\n"
    //           << docStr << std::endl;

    EXPECT_TRUE(docStr.find("<svg width=\"200px\" height=\"200px\"") !=
                std::string::npos);
    EXPECT_TRUE(docStr.find("<circle cx=\"100\" cy=\"100\" r=\"25\"") !=
                std::string::npos);
    EXPECT_TRUE(docStr.find("<text x=\"10\" y=\"180\" fill=\"rgb(0,0,0)\"") !=
                std::string::npos);
}

TEST_F(SVGTest, PathTest)
{
    Document doc;
    Path path(Fill(Color::Yellow), Stroke(2, Color::Purple));
    path << Point(0, 0) << Point(100, 0) << Point(100, 100);
    path.startNewSubPath();
    path << Point(0, 100) << Point(0, 0);
    doc << path;
    std::string docStr = doc.toString();

    // std::cout << "* PathTest docStr:\n"
    //           << docStr << std::endl;

    EXPECT_TRUE(docStr.find("<path") != std::string::npos);
    EXPECT_TRUE(docStr.find("d=\"M0,300 100,300 100,200 z M0,200 0,300 z \"") !=
                std::string::npos);
    EXPECT_TRUE(docStr.find("fill=\"rgb(255,255,0)\"") != std::string::npos);
    EXPECT_TRUE(docStr.find("stroke=\"rgb(128,0,128)\"") != std::string::npos);
    EXPECT_TRUE(docStr.find("stroke-width=\"2\"") != std::string::npos);
}

TEST_F(SVGTest, OriginsTest)
{
    {
        Document doc("test.svg",
                     Layout(Dimensions(200, 200), Layout::BottomLeft));
        doc << Circle(Point(0, 0), 10);  // Circle at origin (0, 0)
        doc << Rectangle(Point(100, 100), 20,
                         45);  // Rectangle at center (100, 100)
        std::string docStr = doc.toString();
        // std::cout << "* OriginsTest docStr:\n" << docStr << std::endl;

        EXPECT_TRUE(docStr.find("<svg width=\"200px\" height=\"200px\"") !=
                    std::string::npos);
        EXPECT_TRUE(docStr.find("<circle cx=\"0\" cy=\"200\" r=\"5\"") !=
                    std::string::npos);
        EXPECT_TRUE(
            docStr.find(
                "<rect x=\"100\" y=\"55\" width=\"20\" height=\"45\"") !=
            std::string::npos);
    }
    {
        Document doc("test.svg", Layout(Dimensions(200, 200), Layout::TopLeft));
        doc << Circle(Point(0, 0), 10);  // Circle at origin (0, 0)
        doc << Rectangle(Point(100, 100), 20,
                         45);  // Rectangle at center (100, 100)
        std::string docStr = doc.toString();
        // std::cout << "* OriginsTest docStr:\n" << docStr << std::endl;

        EXPECT_TRUE(docStr.find("<svg width=\"200px\" height=\"200px\"") !=
                    std::string::npos);
        EXPECT_TRUE(docStr.find("<circle cx=\"0\" cy=\"0\" r=\"5\"") !=
                    std::string::npos);
        EXPECT_TRUE(
            docStr.find(
                "<rect x=\"100\" y=\"100\" width=\"20\" height=\"45\"") !=
            std::string::npos);
    }
    {
        Document doc("test.svg",
                     Layout(Dimensions(200, 200), Layout::BottomRight));
        doc << Circle(Point(0, 0), 10);  // Circle at origin (0, 0)
        doc << Rectangle(Point(100, 100), 20,
                         45);  // Rectangle at center (100, 100)
        std::string docStr = doc.toString();
        // std::cout << "* OriginsTest docStr:\n" << docStr << std::endl;

        EXPECT_TRUE(docStr.find("<svg width=\"200px\" height=\"200px\"") !=
                    std::string::npos);
        EXPECT_TRUE(docStr.find("<circle cx=\"200\" cy=\"200\" r=\"5\"") !=
                    std::string::npos);
        EXPECT_TRUE(
            docStr.find("<rect x=\"80\" y=\"55\" width=\"20\" height=\"45\"") !=
            std::string::npos);
    }
    {
        Document doc("test.svg",
                     Layout(Dimensions(200, 200), Layout::TopRight));
        doc << Circle(Point(0, 0), 10);  // Circle at origin (0, 0)
        doc << Rectangle(Point(100, 100), 20,
                         45);  // Rectangle at center (100, 100)
        std::string docStr = doc.toString();
        // std::cout << "* OriginsTest docStr:\n" << docStr << std::endl;

        EXPECT_TRUE(docStr.find("<svg width=\"200px\" height=\"200px\"") !=
                    std::string::npos);
        EXPECT_TRUE(docStr.find("<circle cx=\"200\" cy=\"0\" r=\"5\"") !=
                    std::string::npos);
        EXPECT_TRUE(
            docStr.find(
                "<rect x=\"80\" y=\"100\" width=\"20\" height=\"45\"") !=
            std::string::npos);
    }
}

TEST_F(SVGTest, LayoutTest)
{
    Layout layoutTopLeft(Dimensions(200, 200), Layout::TopLeft);
    Layout layoutBottomLeft(Dimensions(200, 200), Layout::BottomLeft);

    Circle circle(Point(100, 100), 50);

    std::string circleStrTopLeft = circle.toString(layoutTopLeft);
    std::string circleStrBottomLeft = circle.toString(layoutBottomLeft);

    EXPECT_TRUE(circleStrTopLeft.find("cy=\"100\"") != std::string::npos);
    EXPECT_TRUE(circleStrBottomLeft.find("cy=\"100\"") != std::string::npos);
}

// SimpleSvgTest
// -----------------------------------------------------------------------------------

TEST(SimpleSvgTest, PointSizeAndBoxTest)
{
    Point p1(10, 20);
    Size s1(50, 60);
    Box b1(p1, s1);
    EXPECT_EQ(b1.origin.x, 10);
    EXPECT_EQ(b1.origin.y, 20);
    EXPECT_EQ(b1.size.width, 50);
    EXPECT_EQ(b1.size.height, 60);
}

TEST(SimpleSvgTest, TextTest)
{
    Document doc;
    doc << Text(Point(10, 20), "Hello, SVG!", Fill(Color::Black),
                Font(12, "Arial"));
    std::string docStr = doc.toString();

    // std::cout << "* TextTest docStr:\n" << docStr << std::endl;

    EXPECT_TRUE(docStr.find("<text x=\"10\" y=\"280\"") != std::string::npos);
    EXPECT_TRUE(docStr.find("font-size=\"12\"") != std::string::npos);
    EXPECT_TRUE(docStr.find("font-family=\"Arial\"") != std::string::npos);
    EXPECT_TRUE(docStr.find(">Hello, SVG!</text>") != std::string::npos);
}

TEST(SimpleSvgTest, CircleTest)
{
    Document doc;
    doc << Circle(Point(100, 100), 50, Fill(Color::Red),
                  Stroke(2, Color::Blue));
    std::string docStr = doc.toString();

    // std::cout << "* CircleTest docStr:\n" << docStr << std::endl;

    EXPECT_TRUE(docStr.find("<circle cx=\"100\" cy=\"200\" r=\"25\"") !=
                std::string::npos);  // WHY cy="200"?
    EXPECT_TRUE(docStr.find("fill=\"rgb(255,0,0)\"") != std::string::npos);
    EXPECT_TRUE(docStr.find("stroke=\"rgb(0,0,255)\"") != std::string::npos);
    EXPECT_TRUE(docStr.find("stroke-width=\"2\"") != std::string::npos);
}

TEST(SimpleSvgTest, PolygonTest)
{
    Document doc;
    Polygon polygon(Fill(Color::Green), Stroke(1, Color::Black));
    polygon << Point(0, 0) << Point(100, 0) << Point(100, 100) << Point(0, 100);
    doc << polygon;

    std::string docStr = doc.toString();

    // std::cout << "* PolygonTest docStr:\n"
    //           << docStr << std::endl;

    EXPECT_TRUE(
        docStr.find("<polygon points=\"0,300 100,300 100,200 0,200 \"") !=
        std::string::npos);
    EXPECT_TRUE(docStr.find("fill=\"rgb(0,128,0)\"") != std::string::npos);
    EXPECT_TRUE(docStr.find("stroke=\"rgb(0,0,0)\"") != std::string::npos);
}

TEST(SimpleSvgTest, LineChartTest)
{
    Document doc;
    LineChart chart;
    Polyline line1(Stroke(1, Color::Blue));
    line1 << Point(0, 0) << Point(10, 10) << Point(20, 20);
    Polyline line2(Stroke(1, Color::Red));
    line2 << Point(0, 20) << Point(10, 10) << Point(20, 0);
    chart << line1 << line2;
    doc << chart;
    std::string docStr = doc.toString();

    // std::cout << "* LineChartTest docStr:\n" << docStr << std::endl;

    EXPECT_TRUE(docStr.find("<polyline") != std::string::npos);
    EXPECT_TRUE(docStr.find("stroke=\"rgb(0,0,255)\"") != std::string::npos);
    EXPECT_TRUE(docStr.find("stroke=\"rgb(255,0,0)\"") != std::string::npos);
    EXPECT_TRUE(docStr.find("<circle") != std::string::npos);  // Vertices
}

TEST(SimpleSvgTest, GroupTest)
{
    Document doc;
    Group group(Point(0, 0), Fill(Color::Red), Stroke(2, Color::Black));
    group << Circle(Point(100, 100), 50, Fill(Color::Blue));
    group << Rectangle(Point(200, 200), 100, 50, Fill(Color::Green));
    doc << group;
    std::string docStr = doc.toString();

    // std::cout << "* GroupTest docStr:\n" << docStr << std::endl;

    EXPECT_TRUE(
        docStr.find("rect x=\"0\" y=\"200\" width=\"100\" height=\"100\"") !=
        std::string::npos);
    EXPECT_TRUE(docStr.find("height=\"100\"") != std::string::npos);
    EXPECT_TRUE(docStr.find("fill=\"none\"") != std::string::npos);
    EXPECT_TRUE(docStr.find("stroke-width=\"3\"") != std::string::npos);
    EXPECT_TRUE(docStr.find("stroke=\"rgb(0,0,255)\"") != std::string::npos);
}

TEST(SimpleSvgTest, GroupTest2)
{
    {
        Document doc("test.svg",
                     Layout(Dimensions(400, 300), Layout::BottomLeft));
        doc << Circle(Point(0, 0), 20, Fill(Color::Blue));
        std::string docStr = doc.toString();
        // std::cout << "* GroupTest2 BottomLeft docStr:\n" << docStr <<
        // std::endl;
        (void)docStr;  // No-op use of docStr to satisfy Cppcheck
    }
    {
        Document doc("test.svg", Layout(Dimensions(400, 300), Layout::TopLeft));
        doc << Circle(Point(0, 0), 20, Fill(Color::Blue));
        std::string docStr = doc.toString();
        // std::cout << "* GroupTest2 TopLeft docStr:\n" << docStr << std::endl;
        (void)docStr;  // No-op use of docStr to satisfy Cppcheck
    }
    {
        Document doc("test.svg",
                     Layout(Dimensions(400, 300), Layout::TopRight));
        doc << Circle(Point(0, 0), 20, Fill(Color::Blue));
        std::string docStr = doc.toString();
        // std::cout << "* GroupTest2 TopRight docStr:\n" << docStr <<
        // std::endl;
        (void)docStr;  // No-op use of docStr to satisfy Cppcheck
    }
    {
        Document doc("test.svg",
                     Layout(Dimensions(400, 300), Layout::BottomRight));
        doc << Circle(Point(0, 0), 20, Fill(Color::Blue));
        std::string docStr = doc.toString();
        // std::cout << "* GroupTest2 BottomRight docStr:\n"
        //           << docStr << std::endl;
        (void)docStr;  // No-op use of docStr to satisfy Cppcheck
    }
}

// Run the tests
// -----------------------------------------------------------------------------------
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
