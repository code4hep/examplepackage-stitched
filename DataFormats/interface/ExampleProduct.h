#ifndef DataFormats_ExampleProduct_h
#define DataFormats_ExampleProduct_h

// Note: can not have underscore '_' in the namespace because Stitched
// uses it as delimiter in data product names
namespace examplepackage {
  class ExampleProduct {
  public:
    ExampleProduct() = default;
    ExampleProduct(int v) : value_(v) {}

    int value() const { return value_; }

  private:
    int value_ = 0;
  };
}

#endif
