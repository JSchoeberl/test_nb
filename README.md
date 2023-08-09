# test_nb

First experiments with nanobind

## Needed testing
### Check for [removed features](https://nanobind.readthedocs.io/en/latest/porting.html#removed)
- [ ] No support for Multiple inheritance used in
        BaseMatrix -> S_BaseMatrix<SCAL> ... started to remove
- [ ] Python 3.8
- [ ] No support for custom allocators (overloaded new/delete)

### Derived Python classes
Define derived python class (e.g. Preconditioner), pass reference to it to C++, without holding a reference in python. (Separate branch in pybind11 for this use case)
