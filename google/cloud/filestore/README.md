# Cloud Filestore API C++ Client Library

:construction:

This directory contains an idiomatic C++ client library for the
[Cloud Filestore API][cloud-service-docs], a service to create and manage cloud
file servers.

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

* Official documentation about the [Cloud Filestore API][cloud-service-docs] service
* [Reference doxygen documentation][doxygen-link] for each release of this
  client library
* Detailed header comments in our [public `.h`][source-link] files

[cloud-service-docs]: https://cloud.google.com/filestore
[doxygen-link]: https://googleapis.dev/cpp/google-cloud-filestore/latest/
[source-link]: https://github.com/googleapis/google-cloud-cpp/tree/main/google/cloud/filestore

## Quickstart

The [quickstart/](quickstart/README.md) directory contains a minimal environment
to get started using this client library in a larger project. The following
"Hello World" program is used in this quickstart, and should give you a taste of
this library.

<!-- inject-quickstart-start -->
```cc
#include "google/cloud/filestore/cloud_filestore_manager_client.h"
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) try {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " project-id\n";
    return 1;
  }

  namespace filestore = ::google::cloud::filestore;
  auto client = filestore::CloudFilestoreManagerClient(
      filestore::MakeCloudFilestoreManagerConnection());

  auto const parent = std::string{"projects/"} + argv[1] + "/locations/-";
  for (auto i : client.ListInstances(parent)) {
    if (!i) throw std::runtime_error(i.status().message());
    std::cout << i->DebugString() << "\n";
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
