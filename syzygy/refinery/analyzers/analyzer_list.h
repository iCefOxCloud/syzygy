// Copyright 2015 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SYZYGY_REFINERY_ANALYZERS_ANALYZER_LIST_H_
#define SYZYGY_REFINERY_ANALYZERS_ANALYZER_LIST_H_

#include <string>
#include <vector>

#include "base/strings/string_piece.h"
#include "syzygy/refinery/analyzers/analyzer.h"
#include "syzygy/refinery/process_state/process_state.h"

namespace refinery {

// An analyzer list knows of a set of analyzers and their layer dependencies.
class AnalyzerList {
 public:
  using Layers = std::vector<ProcessState::LayerEnum>;
  using AnalyzerNames = std::vector<std::string>;

  // Retrieves the names of the analyzers known to this analyzer list.
  virtual void GetAnalyzerNames(AnalyzerNames* analyzer_names) const = 0;

  // Creates the analyzer named @p name.
  // @returns the created analyzer, or nullptr if @p name is invalid.
  virtual Analyzer* CreateAnalyzer(const base::StringPiece& name) const = 0;

  // Retrieve the input/output layers for a named analyzer.
  // @param name the name of the analyzer of interest.
  // @param layers on success contains the input/output layers.
  // @returns true on success, false if @p name is invalid.
  // @{
  virtual bool GetInputLayers(const base::StringPiece& name,
                              Layers* layers) const = 0;
  virtual bool GetOutputLayers(const base::StringPiece& name,
                               Layers* layers) const = 0;
  // @}
};

// This implementation of AnalyzerList knows of all analyzers linked into this
// binary.
class StaticAnalyzerList : public AnalyzerList {
 public:
  // @name AnalyzerList implementation.
  // @{
  void GetAnalyzerNames(AnalyzerNames* analyzer_names) const override;
  Analyzer* CreateAnalyzer(const base::StringPiece& name) const override;

  bool GetInputLayers(const base::StringPiece& name,
                      Layers* layers) const override;
  bool GetOutputLayers(const base::StringPiece& name,
                       Layers* layers) const override;
  // @}
};

}  // namespace refinery

#endif  // SYZYGY_REFINERY_ANALYZERS_ANALYZER_LIST_H_
