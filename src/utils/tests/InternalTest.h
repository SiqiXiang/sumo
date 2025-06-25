/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.dev/sumo
// Copyright (C) 2001-2025 German Aerospace Center (DLR) and others.
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// https://www.eclipse.org/legal/epl-2.0/
// This Source Code may also be made available under the following Secondary
// Licenses when the conditions for such availability set forth in the Eclipse
// Public License 2.0 are satisfied: GNU General Public License, version 2
// or later which is available at
// https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
// SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later
/****************************************************************************/
/// @file    InternalTest.h
/// @author  Pablo Alvarez Lopez
/// @date    Mar 2025
///
// Class used for internal tests
/****************************************************************************/
#pragma once
#include <config.h>

#include <string>
#include <vector>
#include <map>

#include <utils/foxtools/fxheader.h>

// ===========================================================================
// class declaration
// ===========================================================================

class InternalTestStep;

// ===========================================================================
// class definitions
// ===========================================================================

class InternalTest : public FXObject {

public:
    /// @brief view position
    struct ViewPosition {
        /// @brief constructor
        ViewPosition() {}

        /// @brief constructor
        ViewPosition(const std::string& xValue, const std::string& yValue);

        /// @brief x value
        int x = 0;

        /// @brief y value
        int y = 0;
    };

    /// @brief contextual menu
    struct ContextualMenu {

        /// @brief default constructor
        ContextualMenu() {}

        /// @brief constructor
        ContextualMenu(const std::string& mainMenuValue, const std::string& subMenuAValue,
                       const std::string& subMenuBValue);

        /// @brief main manue
        int mainMenu = 0;

        /// @brief submenu A
        int subMenuA = 0;

        /// @brief submenu B
        int subMenuB = 0;
    };

    /// @brief constructor
    InternalTest(const std::string& testFile);

    /// @brief destructor
    ~InternalTest();

    /// @brief add test steps
    void addTestSteps(const InternalTestStep* internalTestStep);

    /// @brief get current step
    const InternalTestStep* getCurrentStep() const;

    /// @brief get map with attributesEnum jump steps
    const std::map<std::string, int>& getAttributesEnum() const;

    /// @brief get map with contextual menu operation jump steps
    const std::map<std::string, InternalTest::ContextualMenu>& getContextualMenuOperations() const;

    /// @brief get map with view position pairs
    const std::map<std::string, InternalTest::ViewPosition>& getViewPositions() const;

protected:
    /// @brief current step index
    size_t myCurrentStep = 0;

    /// @brief test steps
    std::vector<const InternalTestStep*> myTestSteps;

    /// @brief vector with attributesEnum jump steps
    std::map<std::string, int> myAttributesEnum;

    /// @brief vector with contextual menu operation jump steps
    std::map<std::string, InternalTest::ContextualMenu> myContextualMenuOperations;

    /// @brief vector with view position pairs
    std::map<std::string, InternalTest::ViewPosition> myViewPositions;

    /// @brief parse attributesEnum file
    std::map<std::string, int> parseAttributesEnumFile(const std::string filePath) const;

    /// @brief parse attributesEnum file
    std::map<std::string, InternalTest::ContextualMenu> parseContextualMenuOperationsFile(const std::string filePath) const;

    /// @brief parse viewPosition file
    std::map<std::string, InternalTest::ViewPosition> parseViewPositionsFile(const std::string filePath) const;

    /// @brief clear lines
    std::vector<std::string> cleanLines(const std::vector<std::pair<bool, std::string> >& linesRaw) const;

    /// @brief check if the given string start with
    bool startWith(const std::string& str, const std::string& prefix) const;

private:
    /// @brief invalidate default constructor
    InternalTest() = delete;

    /// @brief Invalidated copy constructor.
    InternalTest(const InternalTest&) = delete;

    /// @brief Invalidated assignment operator
    InternalTest& operator=(const InternalTest& src) = delete;
};
