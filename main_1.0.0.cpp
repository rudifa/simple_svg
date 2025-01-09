
/*******************************************************************************
*  The "New BSD License" : http://www.opensource.org/licenses/bsd-license.php  *
********************************************************************************

Copyright (c) 2010, Mark Turney
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

******************************************************************************/

#include "simple_svg_1.0.0.hpp"

using namespace svg;

// ShapeColl createSVGElements()
// {
//     ShapeColl elements;

//     // Create a LineChart with Long notation
//     LineChart chart(Dimensions(12.5, 12.5));

//     // Create three Polylines with different colors and strokes
//     Polyline polyline_a(Stroke(1.25, Color::Blue));
//     Polyline polyline_b(Stroke(1.25, Color::Aqua));
//     Polyline polyline_c(Stroke(1.25, Color::Fuchsia));

//     // Add points to each polyline
//     polyline_a << Point(0, 0) << Point(25, 75) << Point(50, 100)
//                << Point(75, 112.5) << Point(100, 110);
//     polyline_b << Point(0, 25) << Point(25, 55) << Point(50, 75)
//                << Point(75, 80) << Point(100, 75);
//     polyline_c << Point(0, 30) << Point(25, 37.5) << Point(50, 35)
//                << Point(75, 25) << Point(100, 5);

//     // Add the polylines to the chart
//     chart << polyline_a << polyline_b << polyline_c;

//     // Add the chart to the elements collection
//     elements << chart;

//     // Create and add another LineChart with Condensed notation
//     elements << (LineChart(Dimensions(162.5, 12.5))
//                  << (Polyline(Stroke(1.25, Color::Blue))
//                      << Point(0, 0) << Point(25, 20) << Point(50, 32.5))
//                  << (Polyline(Stroke(1.25, Color::Orange))
//                      << Point(0, 25) << Point(25, 40) << Point(50, 50))
//                  << (Polyline(Stroke(1.25, Color::Cyan))
//                      << Point(0, 12.5) << Point(25, 32.5) << Point(50, 40)));

//     // Create and add a Circle with specific properties
//     elements << Circle(Point(200, 200), 50, Fill(Color(100, 200, 120)),
//                        Stroke(2.5, Color(200, 250, 150)));

//     // Create and add a Text element with specific properties
//     auto text = Text(Point(12.5, 192.5), "Simple SVG", Fill(Color::Silver),
//                      Font(25, "Verdana"));
//     elements << text;

//     // Create and add a Rectangle to represent the Text bounding box
//     auto bb = text.getBoundingBox();
//     elements << Rectangle(bb.origin, bb.size.width, bb.size.height,
//                           Fill(Color::Transparent), Stroke(1, Color::Red));

//     // Create and add a Polygon with specific properties
//     elements << (Polygon(Fill(Color(200, 160, 220)),
//                          Stroke(1.25, Color(150, 160, 200)))
//                  << Point(50, 175) << Point(62.5, 180) << Point(82.5, 175)
//                  << Point(87.5, 150) << Point(62.5, 137.5) << Point(45,
//                  157.5));

//     // Create and add a Rectangle with specific properties
//     elements << Rectangle(Point(175, 137.5), 50, 37.5, Fill(Color::Yellow),
//                           Stroke(1, Color::Black));

//     // Create an ellipse with specific properties
//     elements << Elipse(Point(200, 120), 50, 25, Fill(Color::Red),
//                        Stroke(1.5, Color::Black));

//     // Return the collection of SVG elements
//     return elements;
// }

// // Demo page shows sample usage of the Simple SVG library.

// void demoDocLayout(const Layout &layout)
// {
//     std::string filename;
//     switch (origin)
//     {
//         case Layout::TopLeft:
//             filename = "svg1_topleft.svg";
//             break;
//         case Layout::TopRight:
//             filename = "svg1_topright.svg";
//             break;
//         case Layout::BottomLeft:
//             filename = "svg1_bottomleft.svg";
//             break;
//         case Layout::BottomRight:
//             filename = "svg1_bottomright.svg";
//             break;
//     }

//     Dimensions dimensions(400, 400);

//     // Mark origin and the farthest point in the layout with circles
//     doc << Circle(Point(0, 0), 20, Fill(Color::Red), Stroke(1,
//     Color::Black)); doc << Circle(
//         Point(layout.dimensions.width - 10, layout.dimensions.height - 10),
//         20, Fill(Color::Red), Stroke(1, Color::Black));

//     // Create and add all demo shapes
//     ShapeColl elements = createSVGElements();
//     doc << elements;

//     // Save document and report status
//     if (doc.save())
//     {
//         std::cout << "File saved successfully: " << filename << std::endl;
//     }
//     else
//     {
//         std::cout << "Failed to save the file: " << filename << std::endl;
//     }
// }

// ShapeColl createSVGElements()
// {
//     ShapeColl elements;

//     // Create a LineChart with Long notation
//     LineChart chart(Dimensions(12.5, 12.5));

//     // Create three Polylines with different colors and strokes
//     Polyline polyline_a(Stroke(1.25, Color::Blue));
//     Polyline polyline_b(Stroke(1.25, Color::Aqua));
//     Polyline polyline_c(Stroke(1.25, Color::Fuchsia));

//     // Add points to each polyline
//     polyline_a << Point(0, 0) << Point(25, 75) << Point(50, 100)
//                << Point(75, 112.5) << Point(100, 110);
//     polyline_b << Point(0, 25) << Point(25, 55) << Point(50, 75)
//                << Point(75, 80) << Point(100, 75);
//     polyline_c << Point(0, 30) << Point(25, 37.5) << Point(50, 35)
//                << Point(75, 25) << Point(100, 5);

//     // Add the polylines to the chart
//     chart << polyline_a << polyline_b << polyline_c;

//     // Add the chart to the elements collection
//     elements << chart;

//     // Create and add another LineChart with Condensed notation
//     elements << (LineChart(Dimensions(162.5, 12.5))
//                  << (Polyline(Stroke(1.25, Color::Blue))
//                      << Point(0, 0) << Point(25, 20) << Point(50, 32.5))
//                  << (Polyline(Stroke(1.25, Color::Orange))
//                      << Point(0, 25) << Point(25, 40) << Point(50, 50))
//                  << (Polyline(Stroke(1.25, Color::Cyan))
//                      << Point(0, 12.5) << Point(25, 32.5) << Point(50, 40)));

//     // Create and add a Circle with specific properties
//     elements << Circle(Point(200, 200), 50, Fill(Color(100, 200, 120)),
//                        Stroke(2.5, Color(200, 250, 150)));

//     // Create and add a Text element with specific properties
//     auto text = Text(Point(12.5, 192.5), "Simple SVG", Fill(Color::Silver),
//                      Font(25, "Verdana"));
//     elements << text;

//     // Create and add a Rectangle to represent the Text bounding box
//     auto bb = text.getBoundingBox();
//     elements << Rectangle(bb.origin, bb.size.width, bb.size.height,
//                           Fill(Color::Transparent), Stroke(1, Color::Red));

//     // Create and add a Polygon with specific properties
//     elements << (Polygon(Fill(Color(200, 160, 220)),
//                          Stroke(1.25, Color(150, 160, 200)))
//                  << Point(50, 175) << Point(62.5, 180) << Point(82.5, 175)
//                  << Point(87.5, 150) << Point(62.5, 137.5) << Point(45,
//                  157.5));

//     // Create and add a Rectangle with specific properties
//     elements << Rectangle(Point(175, 137.5), 50, 37.5, Fill(Color::Yellow),
//                           Stroke(1, Color::Black));

//     // Create an ellipse with specific properties
//     elements << Elipse(Point(200, 120), 50, 25, Fill(Color::Red),
//                        Stroke(1.5, Color::Black));

//     elements.offset(Point(250, 250));  // move all elements to the right

//     // Return the collection of SVG elements
//     return elements;
// }

// // Demo page shows sample usage of the Simple SVG library.

// void demoDocLayout(const Layout &layout)
// {
//     // Generate filename based on the layout origin type
//     std::string filename;
//     switch (layout.origin)
//     {
//         case Layout::TopLeft:
//             filename = "svg_topleft.svg";
//             break;
//         case Layout::TopRight:
//             filename = "svg_topright.svg";
//             break;
//         case Layout::BottomLeft:
//             filename = "svg_bottomleft.svg";
//             break;
//         case Layout::BottomRight:
//             filename = "svg_bottomright.svg";
//             break;
//     }

//     // Create SVG document with specified layout
//     Document doc(filename, layout);

//     // Draw border rectangle using document dimensions
//     Polygon border(Stroke(1, Color::Red));
//     border << Point(0, 0) << Point(layout.dimensions.width, 0)
//            << Point(layout.dimensions.width, layout.dimensions.height)
//            << Point(0, layout.dimensions.height);
//     doc << border;

//     // Mark origin and the farthest point in the layout with circles
//     doc << Circle(Point(0, 0), 20, Fill(Color::Red), Stroke(1,
//     Color::Black)); doc << Circle(
//         Point(layout.dimensions.width - 10, layout.dimensions.height - 10),
//         20, Fill(Color::Red), Stroke(1, Color::Black));

//     // Create and add all demo shapes
//     ShapeColl elements = createSVGElements();
//     doc << elements;

//     // Save document and report status
//     if (doc.save())
//     {
//         std::cout << "File saved successfully: " << filename << std::endl;
//     }
//     else
//     {
//         std::cout << "Failed to save the file: " << filename << std::endl;
//     }
// }

// void main1()  // Example usage of the Simple SVG library.
// {
//     // demo1();
//     demo2(Layout::BottomLeft);
//     demo2(Layout::TopLeft);
//     demo2(Layout::BottomRight);
//     demo2(Layout::TopRight);
// }

// int main()
// {
//     try
//     {
//         // Set canvas dimensions for all layouts
//         Dimensions dimensions(500, 500);

//         // Define array of all possible coordinate system origins
//         const Layout::Origin origins[] = {Layout::TopLeft, Layout::TopRight,
//                                           Layout::BottomLeft,
//                                           Layout::BottomRight};

//         // Generate SVG file for each coordinate system origin
//         for (Layout::Origin origin : origins)
//         {
//             Layout layout(dimensions, origin);
//             demoDocLayout(layout);
//         }

//         main1();
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << "An exception occurred: " << e.what() << std::endl;
//     }
//     catch (...)
//     {
//         std::cerr << "An unknown exception occurred." << std::endl;
//     }
//     return 0;
// }

// Demo page shows sample usage of the Simple SVG library.

void demo1()
{
    const std::string filename = "my_svg.svg";
    Dimensions dimensions(600, 600);
    Document doc(filename, Layout(dimensions, Layout::BottomLeft));

    // Blue document border
    Polygon docBorder(Stroke(1, Color::Blue));
    docBorder << Point(0, 0) << Point(dimensions.width, 0)
              << Point(dimensions.width, dimensions.height)
              << Point(0, dimensions.height);
    doc << docBorder;

    // Red image border.
    Polygon border(Stroke(1, Color::Red));
    border << Point(0, 0) << Point(dimensions.width / 2, 0)
           << Point(dimensions.width / 2, dimensions.height / 2)
           << Point(0, dimensions.height / 2);
    doc << border;

    // Long notation.  Local variable is created, children are added to
    // varaible.
    LineChart chart(Dimensions(), 12.5, Stroke(0.5, Color::Purple));
    Polyline polyline_a(Stroke(3.0, Color::Blue));
    Polyline polyline_b(Stroke(3.0, Color::Aqua));
    Polyline polyline_c(Stroke(3.0, Color::Fuchsia));
    polyline_a << Point(0, 0) << Point(25, 75) << Point(50, 100)
               << Point(75, 112.5) << Point(100, 110);
    polyline_b << Point(0, 25) << Point(25, 55) << Point(50, 75)
               << Point(75, 80) << Point(100, 75);
    polyline_c << Point(0, 30) << Point(25, 37.5) << Point(50, 35)
               << Point(75, 25) << Point(100, 5);
    chart << polyline_a << polyline_b << polyline_c;
    doc << chart;

    // Condensed notation, parenthesis isolate temporaries that are inserted
    // into parents.
    doc << (LineChart(Dimensions(162.5, 12.5))
            << (Polyline(Stroke(2.5, Color::Blue))
                << Point(0, 0) << Point(25, 20) << Point(50, 32.5))
            << (Polyline(Stroke(2.5, Color::Orange))
                << Point(0, 25) << Point(25, 40) << Point(50, 50))
            << (Polyline(Stroke(2.5, Color::Cyan))
                << Point(0, 12.5) << Point(25, 32.5) << Point(50, 40)));

    doc << Circle(Point(200, 200), 50, Fill(Color(100, 200, 120)),
                  Stroke(5, Color(200, 250, 150)));

    doc << Text(Point(12.5, 192.5), "Simple SVG", Fill(Color::Silver),
                Font(25, "Verdana"));

    doc << (Polygon(Fill(Color(200, 160, 220)),
                    Stroke(2.5, Color(150, 160, 200)))
            << Point(50, 175) << Point(62.5, 180) << Point(82.5, 175)
            << Point(87.5, 150) << Point(62.5, 137.5) << Point(45, 157.5));

    Rectangle rect(Point(175, 137.5), 50, 37.5, Fill(Color::Yellow));
    rect.setRotation(60);
    doc << rect;

    Group myGroup(Point(200, 200), Fill(Color::Red), Stroke(2, Color::Black));
    myGroup << Circle(Point(100, 100), 50, Fill(Color::Blue))
            << Rectangle(Point(200, 200), 50, 50, Fill(Color::Green))
            << Rectangle(Point(300, 200), 50, 50, Fill(Color::Green));

    Text text(Point(0, 0), "Hello world!", Fill(Color::Black),
              Font(10, "Verdana"), Stroke(), 0);

    myGroup << text;

    text.setRotation(-5);  // Rotate the text 45 degrees
    myGroup << text;       // Add the text to the group

    doc << myGroup;

    doc.save();

    std::cout << "SVG saved to: " << filename << std::endl;

    system(
        ("open " + filename).c_str());  // Open the file in the default browser
}

void demo2(Layout::Origin origin = Layout::BottomLeft)
{
    std::string filename;
    switch (origin)
    {
        case Layout::TopLeft:
            filename = "svg1_topleft.svg";
            break;
        case Layout::TopRight:
            filename = "svg1_topright.svg";
            break;
        case Layout::BottomLeft:
            filename = "svg1_bottomleft.svg";
            break;
        case Layout::BottomRight:
            filename = "svg1_bottomright.svg";
            break;
    }

    Dimensions dimensions(400, 400);

    // Create a Document object with the specified layout
    Document doc(filename, Layout(dimensions, origin));

    // Blue document border
    {
        Polygon docBorder(Stroke(1, Color::Blue));
        docBorder << Point(0, 0) << Point(dimensions.width, 0)
                  << Point(dimensions.width, dimensions.height)
                  << Point(0, dimensions.height);
        doc << docBorder;
    }

    // Circle at the origin
    {
        doc << Circle(Point(0, 0), 50, Fill(Color::Green));
    }
    // Circles in the corners
    {
        doc << Circle(Point(25, 25), 50, Fill(Color::Transparent),
                      Stroke(2.0, Color::Red));
        doc << Circle(Point(375, 375), 50, Fill(Color::Red));
    }

    // Rectangle in the center, should go up and right
    {
        doc << Rectangle(Point(200, 200), 50, 100, Fill(),
                         Stroke(2.0, Color::Red));
    }

    {
        doc << Rectangle(Point(200, 200), 150, 50, Fill(),
                         Stroke(2.0, Color::Blue));
    }

    Group myGroup(Point(0, 0), Fill(Color::Red), Stroke(2, Color::Black));

    myGroup << Circle(Point(0, 0), 30, Fill(Color::Blue))
            << Rectangle(Point(100, 100), 100, 50, Fill(Color::Transparent));

    Text text(Point(100, 100), "Hello group!", Fill(Color::Black),
              Font(10, "Verdana"), Stroke(), 0);
    myGroup << text;

    text.setRotation(-45);
    myGroup << text;

    text.setRotation(-90);
    myGroup << text;

    doc << myGroup;

    doc.save();

    std::cout << "SVG saved to: " << filename << std::endl;

    // system(
    //     ("open " + filename).c_str());  // Open the file in the default
    //     browser
}

ShapeColl createSVGElements()
{
    ShapeColl elements;

    // Create a LineChart with Long notation
    LineChart chart(Dimensions(12.5, 12.5));

    // Create three Polylines with different colors and strokes
    Polyline polyline_a(Stroke(1.25, Color::Blue));
    Polyline polyline_b(Stroke(1.25, Color::Aqua));
    Polyline polyline_c(Stroke(1.25, Color::Fuchsia));

    // Add points to each polyline
    polyline_a << Point(0, 0) << Point(25, 75) << Point(50, 100)
               << Point(75, 112.5) << Point(100, 110);
    polyline_b << Point(0, 25) << Point(25, 55) << Point(50, 75)
               << Point(75, 80) << Point(100, 75);
    polyline_c << Point(0, 30) << Point(25, 37.5) << Point(50, 35)
               << Point(75, 25) << Point(100, 5);

    // Add the polylines to the chart
    chart << polyline_a << polyline_b << polyline_c;

    // Add the chart to the elements collection
    elements << chart;

    // Create and add another LineChart with Condensed notation
    elements << (LineChart(Dimensions(162.5, 12.5))
                 << (Polyline(Stroke(1.25, Color::Blue))
                     << Point(0, 0) << Point(25, 20) << Point(50, 32.5))
                 << (Polyline(Stroke(1.25, Color::Orange))
                     << Point(0, 25) << Point(25, 40) << Point(50, 50))
                 << (Polyline(Stroke(1.25, Color::Cyan))
                     << Point(0, 12.5) << Point(25, 32.5) << Point(50, 40)));

    // Create and add a Circle with specific properties
    elements << Circle(Point(200, 200), 50, Fill(Color(100, 200, 120)),
                       Stroke(2.5, Color(200, 250, 150)));

    // Create and add a Text element with specific properties
    auto text = Text(Point(12.5, 192.5), "Simple SVG", Fill(Color::Silver),
                     Font(25, "Verdana"));
    elements << text;

    // Create and add a Rectangle to represent the Text bounding box
    auto bb = text.getBoundingBox();
    elements << Rectangle(bb.origin, bb.size.width, bb.size.height,
                          Fill(Color::Transparent), Stroke(1, Color::Red));

    // Create and add a Polygon with specific properties
    elements << (Polygon(Fill(Color(200, 160, 220)),
                         Stroke(1.25, Color(150, 160, 200)))
                 << Point(50, 175) << Point(62.5, 180) << Point(82.5, 175)
                 << Point(87.5, 150) << Point(62.5, 137.5) << Point(45, 157.5));

    // Create and add a Rectangle with specific properties
    elements << Rectangle(Point(175, 137.5), 50, 37.5, Fill(Color::Yellow),
                          Stroke(1, Color::Black));

    // Create an ellipse with specific properties
    elements << Elipse(Point(200, 120), 50, 25, Fill(Color::Red),
                       Stroke(1.5, Color::Black));

    elements.offset(Point(250, 250));  // move all elements to the right

    // Return the collection of SVG elements
    return elements;
}

// Demo page shows sample usage of the Simple SVG library.

void demoDocLayout(const Layout &layout)
{
    // Generate filename based on the layout origin type
    std::string filename;
    switch (layout.origin)
    {
        case Layout::TopLeft:
            filename = "svg_topleft.svg";
            break;
        case Layout::TopRight:
            filename = "svg_topright.svg";
            break;
        case Layout::BottomLeft:
            filename = "svg_bottomleft.svg";
            break;
        case Layout::BottomRight:
            filename = "svg_bottomright.svg";
            break;
    }

    // Create SVG document with specified layout
    Document doc(filename, layout);

    // Draw border rectangle using document dimensions
    Polygon border(Stroke(1, Color::Red));
    border << Point(0, 0) << Point(layout.dimensions.width, 0)
           << Point(layout.dimensions.width, layout.dimensions.height)
           << Point(0, layout.dimensions.height);
    doc << border;

    // Mark origin and the farthest point in the layout with circles
    doc << Circle(Point(0, 0), 20, Fill(Color::Red), Stroke(1, Color::Black));
    doc << Circle(
        Point(layout.dimensions.width - 10, layout.dimensions.height - 10), 20,
        Fill(Color::Red), Stroke(1, Color::Black));

    // Create and add all demo shapes
    ShapeColl elements = createSVGElements();
    doc << elements;

    // Save document and report status
    if (doc.save())
    {
        std::cout << "File saved successfully: " << filename << std::endl;
    }
    else
    {
        std::cout << "Failed to save the file: " << filename << std::endl;
    }
}

void main1()  // Example usage of the Simple SVG library.
{
    // demo1();
    demo2(Layout::BottomLeft);
    demo2(Layout::TopLeft);
    demo2(Layout::BottomRight);
    demo2(Layout::TopRight);
}

int main()
{
    try
    {
        // Set canvas dimensions for all layouts
        Dimensions dimensions(500, 500);

        // Define array of all possible coordinate system origins
        const Layout::Origin origins[] = {Layout::TopLeft, Layout::TopRight,
                                          Layout::BottomLeft,
                                          Layout::BottomRight};

        // Generate SVG file for each coordinate system origin
        for (Layout::Origin origin : origins)
        {
            Layout layout(dimensions, origin);
            demoDocLayout(layout);
        }

        main1();
    }
    catch (const std::exception &e)
    {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "An unknown exception occurred." << std::endl;
    }
    return 0;
}
