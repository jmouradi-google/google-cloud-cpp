# Contact Center AI Insights API C++ Client Library

:construction:

This directory contains an idiomatic C++ client library for the
[Contact Center AI Insights API][cloud-service-docs], a service that helps users
detect and visualize patterns in their contact center data.

This library is **experimental**. Its APIs are subject to change without notice.

Please note that the Google Cloud C++ client libraries do **not** follow
[Semantic Versioning](https://semver.org/).

## Supported Platforms

* Windows, macOS, Linux
* C++11 (and higher) compilers (we test with GCC >= 5.4, Clang >= 6.0, and
  MSVC >= 2017)
* Environments with or without exceptions
* Bazel and CMake builds

## Documentation

* Official documentation about the [Contact Center AI Insights API][cloud-service-docs] service
* [Reference doxygen documentation][doxygen-link] for each release of this
  client library
* Detailed header comments in our [public `.h`][source-link] files

[cloud-service-docs]: https://cloud.google.com/contact-center/insights/docs
[doxygen-link]: https://googleapis.dev/cpp/google-cloud-contactcenterinsights/latest/
[source-link]: https://github.com/googleapis/google-cloud-cpp/tree/main/google/cloud/contactcenterinsights

## Quickstart

The [quickstart/](quickstart/README.md) directory contains a minimal environment
to get started using this client library in a larger project. The following
"Hello World" program is used in this quickstart, and should give you a taste of
this library.

<!-- inject-quickstart-start -->
```cc
#include "google/cloud/contactcenterinsights/contact_center_insights_client.h"
#include <google/protobuf/util/time_util.h>
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) try {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " project-id location-id\n";
    return 1;
  }

  namespace ccai = ::google::cloud::contactcenterinsights;
  auto client = ccai::ContactCenterInsightsClient(
      ccai::MakeContactCenterInsightsConnection());

  auto const parent =
      std::string{"projects/"} + argv[1] + "/locations/" + argv[2];
  for (auto c : client.ListConversations(parent)) {
    if (!c) throw std::runtime_error(c.status().message());

    using ::google::protobuf::util::TimeUtil;
    std::cout << c->name() << "\n";
    std::cout << "Duration: " << TimeUtil::ToString(c->duration())
              << "; Turns: " << c->turn_count() << "\n\n";
  }

  return 0;
} catch (std::exception const& ex) {
  std::cerr << "Standard exception raised: " << ex.what() << "\n";
  return 1;
}
```
<!-- inject-quickstart-end -->

* Packaging maintainers or developers who prefer to install the library in a
  fixed directory (such as `/usr/local` or `/opt`) should consult the
  [packaging guide](/doc/packaging.md).
* Developers wanting to use the libraries as part of a larger CMake or Bazel
  project should consult the [quickstart guides](#quickstart) for the library
  or libraries they want to use.
* Developers wanting to compile the library just to run some of the examples or
  tests should read the current document.
* Contributors and developers to `google-cloud-cpp` should consult the guide to
  [setup a development workstation][howto-setup-dev-workstation].

[howto-setup-dev-workstation]: /doc/contributor/howto-guide-setup-development-workstation.md

## Contributing changes

See [`CONTRIBUTING.md`](../../../CONTRIBUTING.md) for details on how to
contribute to this project, including how to build and test your changes
as well as how to properly format your code.

## Licensing

Apache 2.0; see [`LICENSE`](../../../LICENSE) for details.
