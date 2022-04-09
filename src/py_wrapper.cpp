#include <python3.10/pyconfig.h>
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include "example.hpp"

// define boost.python module
BOOST_PYTHON_MODULE(pyexample)
{
    using namespace boost::python;

    def("exampleFunction", &exampleFunction);
    
    class_<MyClass>("MyClass")
        .def("square", &MyClass::square)
        .def("returnList", &MyClass::returnList)
        .def("sum", &MyClass::sum)
    ;

    // Boost container indexing for vectors
    
    class_<std::vector<int> >("IntVec")
        .def(vector_indexing_suite<std::vector<int> >())
        .def("size", &vector_indexing_suite<std::vector<int> >::size)
    ;

    class_<std::vector<vector<int>> >("IntVecVec")
        .def(vector_indexing_suite<std::vector<vector<int>> >())
        .def("size", &vector_indexing_suite<std::vector<vector<int>> >::size)
    ;

    class_<std::vector<vector<vector<int>>> >("IntVecVecVec")
        .def(vector_indexing_suite<std::vector<vector<vector<int>>> >())
        .def("size", &vector_indexing_suite<std::vector<vector<vector<int>>> >::size)
    ;
}