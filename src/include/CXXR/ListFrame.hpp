/*
 *  R : A Computer Language for Statistical Data Analysis
 *  Copyright (C) 1995, 1996  Robert Gentleman and Ross Ihaka
 *  Copyright (C) 1999-2006   The R Development Core Team.
 *  Copyright (C) 2008-2014  Andrew R. Runnalls.
 *  Copyright (C) 2014 and onwards the CXXR Project Authors.
 *
 *  CXXR is not part of the R project, and bugs and other issues should
 *  not be reported via r-bugs or other R project channels; instead refer
 *  to the CXXR website.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2.1 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, a copy is available at
 *  http://www.r-project.org/Licenses/
 */

/** @file ListFrame.hpp
 *
 * @brief Class CXXR::ListFrame.
 */

#ifndef LISTFRAME_HPP
#define LISTFRAME_HPP

#include <list>

#include "CXXR/Allocator.hpp"
#include "CXXR/Frame.hpp"

namespace CXXR {
    /** @brief Lightweight implementation of CXXR::Frame.
     *
     * This implementation is intended for Frames containing only a
     * small number of Bindings.  Look-up time is linear in the number
     * of Bindings.
     */
    class ListFrame : public Frame {
    private:
	typedef
	std::list<Binding, CXXR::Allocator<Binding> > List;
    public:
	ListFrame() { }
	ListFrame(const ListFrame &pattern);

	// Virtual functions of Frame (qv):
	void visitBindings(std::function<void(const Binding*)> f)
	    const override;
	ListFrame* clone() const override;
	void lockBindings() override;
	std::size_t size() const override;
    private:
	List m_list;

	// Declared private to ensure that ListFrame objects are
	// created only using 'new':
	~ListFrame() {}

	// Not (yet) implemented.  Declared to prevent
	// compiler-generated versions:
	ListFrame& operator=(const ListFrame&);

	// Virtual functions of Frame (qv):
	void v_clear() override;
	bool v_erase(const Symbol* symbol) override;
	Binding* v_obtainBinding(const Symbol* symbol) override;
	Binding* v_binding(const Symbol* symbol) override;
	const Binding* v_binding(const Symbol* symbol) const override;
     };

}  // namespace CXXR
#endif // LISTFRAME_HPP
