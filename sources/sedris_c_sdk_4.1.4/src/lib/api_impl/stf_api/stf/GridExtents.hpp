// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        GridExtents.hpp
//
// PROGRAMMERS: John E. Carswell
//
// DESCRIPTION: Class header for the derived class GridExtents
//
// - STF spec. 4.1

/*
 *                             NOTICE
 * 
 * This software is provided openly and freely for use in representing and
 * interchanging environmental data & databases.
 * 
 * This software was developed for use by the United States Government with
 * unlimited rights.  The software was developed under contract
 * DASG60-02-D-0006 TO-193 by Science Applications International Corporation.
 * The software is unclassified and is deemed as Distribution A, approved
 * for Public Release.
 * 
 * Use by others is permitted only upon the ACCEPTANCE OF THE TERMS AND
 * CONDITIONS, AS STIPULATED UNDER THE FOLLOWING PROVISIONS:
 * 
 *    1. Recipient may make unlimited copies of this software and give
 *       copies to other persons or entities as long as the copies contain
 *       this NOTICE, and as long as the same copyright notices that
 *       appear on, or in, this software remain.
 * 
 *    2. Trademarks. All trademarks belong to their respective trademark
 *       holders.  Third-Party applications/software/information are
 *       copyrighted by their respective owners.
 * 
 *    3. Recipient agrees to forfeit all intellectual property and
 *       ownership rights for any version created from the modification
 *       or adaptation of this software, including versions created from
 *       the translation and/or reverse engineering of the software design.
 * 
 *    4. Transfer.  Recipient may not sell, rent, lease, or sublicense
 *       this software.  Recipient may, however enable another person
 *       or entity the rights to use this software, provided that this
 *       AGREEMENT and NOTICE is furnished along with the software and
 *       /or software system utilizing this software.
 * 
 *       All revisions, modifications, created by the Recipient, to this
 *       software and/or related technical data shall be forwarded by the
 *       Recipient to the Government at the following address:
 * 
 *         SMDC
 *         Attention SEDRIS (TO193) TPOC
 *         P.O. Box 1500
 *         Huntsville, AL  35807-3801
 * 
 *         or via electronic mail to:  se-mgmt@sedris.org
 * 
 *    5. No Warranty. This software is being delivered to you AS IS
 *       and there is no warranty, EXPRESS or IMPLIED, as to its use
 *       or performance.
 * 
 *       The RECIPIENT ASSUMES ALL RISKS, KNOWN AND UNKNOWN, OF USING
 *       THIS SOFTWARE.  The DEVELOPER EXPRESSLY DISCLAIMS, and the
 *       RECIPIENT WAIVES, ANY and ALL PERFORMANCE OR RESULTS YOU MAY
 *       OBTAIN BY USING THIS SOFTWARE OR DOCUMENTATION.  THERE IS
 *       NO WARRANTY, EXPRESS OR, IMPLIED, AS TO NON-INFRINGEMENT OF
 *       THIRD PARTY RIGHTS, MERCHANTABILITY, OR FITNESS FOR ANY
 *       PARTICULAR PURPOSE.  IN NO EVENT WILL THE DEVELOPER, THE
 *       UNITED STATES GOVERNMENT OR ANYONE ELSE ASSOCIATED WITH THE
 *       DEVELOPMENT OF THIS SOFTWARE BE HELD LIABLE FOR ANY CONSEQUENTIAL,
 *       INCIDENTAL OR SPECIAL DAMAGES, INCLUDING ANY LOST PROFITS
 *       OR LOST SAVINGS WHATSOEVER.
 */

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 */

#ifndef _GRID_EXTENTS_HPP_INCLUDED
#define _GRID_EXTENTS_HPP_INCLUDED

#include <stdio.h>
#include <sys/types.h>

#include "../../RAIF/se_STL_includes.h"
#include "se_extract_types.h"


#if defined(__IBMCPP__)
#include <stdlib.h>
#include <ctype.h>
#endif

#if defined (__IBMCPP__) || defined (darwin_cc) || defined (gnu) || defined (ms_net)
#define STF_STL_TYPE
#else
    #if defined (_WIN32) && _MSC_VER >= 1300
        #define STF_STL_TYPE
    #endif
#endif

template <class T> class GridSubExtents;
template <class T> class GridExtentsList;
template <class T> class GridExtents;

template <class T1, class T2>
    bool Intersect(const GridExtents<T1>& extA, const GridExtents<T2>& extB);

template < class T > class GridExtents
{
  public:
    //
    // Forward declarations of helper classes
    //
    class iterator;
    friend class iterator;
    friend class GridSubExtents<T>;

    //
    // Helpful typedefs
    //
    typedef GridExtents<T>                   my_type;
    typedef T                                value_type;
    typedef value_type                      *pointer;
    typedef value_type                      &reference;
    typedef const value_type                &const_reference;

    typedef GridExtentsList<T>  list_type;
    typedef unsigned int        index_type;


    //
    // Public constructors and the destructor.
    //
  public:
    GridExtents()
        : axesCount(0),
          startArray(NULL),
          stopArray(NULL),
          dataMinIndx(NULL),
          dataMaxIndx(NULL),
          axisElementCount(NULL),
          axisElementOffset(NULL),
          dataPtr(NULL),
          elementSize(sizeof(T))
                            {
                            }

    GridExtents(int numAxes, const SE_Index_Range* bounds,
                       pointer data = NULL,
                       unsigned int elemSize = sizeof(T))
        : axesCount(numAxes),
          dataMinIndx(NULL),
          dataMaxIndx(NULL),
          axisElementCount(NULL),
          axisElementOffset(NULL),
          dataPtr(data),
          elementSize(elemSize)
    {
        index_type i;
        //
        // Copy the start array.  This base class constructor sets the
        // dataMinIndx so that it reuses the values of the start array.
        //
        startArray = new index_type[axesCount];
        dataMinIndx = startArray;

        if (bounds != NULL)
        {
            for (i = 0; i < axesCount; i++)
                startArray[i] = bounds[i].first_index;
        }
        else
            memset(startArray, 0, axesCount*sizeof(index_type));

        //
        // Do the same for the stop array and dataMaxIndx
        //
        stopArray = new index_type[axesCount];
        dataMaxIndx = stopArray;

        if (bounds != NULL)
        {
            for (i = 0; i < axesCount; i++)
                stopArray[i] = bounds[i].last_index;
        }
        else
            memset(stopArray, 0, axesCount*sizeof(index_type));

        Reset();
    }

    GridExtents(int numAxes, const SE_Short_Integer_Unsigned* starts,
                       const SE_Short_Integer_Unsigned* stops, pointer data = NULL,
                       unsigned int elemSize = sizeof(T))
        : axesCount(numAxes),
          dataMinIndx(NULL),
          dataMaxIndx(NULL),
          axisElementCount(NULL),
          axisElementOffset(NULL),
          dataPtr(data),
          elementSize(elemSize)
    {
        index_type i;
        //
        // Copy the start array.  This base class constructor sets the
        // dataMinIndx so that it reuses the values of the start array.
        //
        startArray = new index_type[axesCount];
        dataMinIndx = startArray;

        if (starts != NULL)
        {
            for (i = 0; i < axesCount; i++)
                startArray[i] = starts[i];
        }
        else
            memset(startArray, 0, axesCount*sizeof(index_type));

        //
        // Do the same for the stop array and dataMaxIndx
        //
        stopArray = new index_type[axesCount];
        dataMaxIndx = stopArray;

        if (stops != NULL)
        {
            for (i = 0; i < axesCount; i++)
                stopArray[i] = stops[i];
        }
        else
            memset(stopArray, 0, axesCount*sizeof(index_type));

        Reset();
    }

    GridExtents(int numAxes, const SE_Integer_Unsigned* starts,
                       const SE_Integer_Unsigned* stops, pointer data = NULL,
                       unsigned int elemSize = sizeof(T))
        : axesCount(numAxes),
          dataMinIndx(NULL),
          dataMaxIndx(NULL),
          axisElementCount(NULL),
          axisElementOffset(NULL),
          dataPtr(data),
          elementSize(elemSize)
    {
        index_type        i;
        //
        // Copy the start array.  This base class constructor sets the
        // dataMinIndx so that it reuses the values of the start array.
        //
        startArray = new index_type[axesCount];
        dataMinIndx = startArray;

        if (starts != NULL)
        {
            for (i = 0; i < axesCount; i++)
                startArray[i] = starts[i];
        }
        else
            memset(startArray, 0, axesCount*sizeof(index_type));

        //
        // Do the same for the stop array and dataMaxIndx
        //
        stopArray = new index_type[axesCount];
        dataMaxIndx = stopArray;

        if (stops != NULL)
        {
            for (i = 0; i < axesCount; i++)
                stopArray[i] = stops[i];
        }
        else
            memset(stopArray, 0, axesCount*sizeof(index_type));

        Reset();
    }

    GridExtents(const vector<SE_Integer_Unsigned >& sizeVect,
                       pointer data = NULL, unsigned int elemSize = sizeof(T))
        : axesCount(0),
          startArray(NULL),
          stopArray(NULL),
          dataMinIndx(NULL),
          dataMaxIndx(NULL),
          axisElementCount(NULL),
          axisElementOffset(NULL),
          dataPtr(data),
          elementSize(elemSize)
    {
        index_type *tmpIndx = NULL;
        unsigned int i;

        tmpIndx = new index_type[sizeVect.size()];

        for(i=0; i < sizeVect.size(); i++)
        {
            tmpIndx[i] = sizeVect[i];
        }

        my_type   tmpExt(sizeVect.size(), tmpIndx, data, elemSize);

        *this = tmpExt;

        delete[] tmpIndx;
    }

    GridExtents(int numAxes, const unsigned int* axisSizes,
                       pointer data = NULL, unsigned int elemSize = sizeof(T))
        : axesCount(numAxes),
          dataMinIndx(NULL),
          dataMaxIndx(NULL),
          axisElementCount(NULL),
          axisElementOffset(NULL),
          dataPtr(data),
          elementSize(elemSize)
    {
        //
        // Create the start array.  This base class constructor sets
        // the dataMinIndx so that is reuses the values of the start array.
        // In this version of the constructor, the start array is
        // initialized to 0;
        //
        startArray = new index_type[axesCount];
        dataMinIndx = startArray;

        memset(startArray, 0, axesCount*sizeof(index_type));

        //
        // Create the stop array in a fashion similar to the start array.
        // If a size array was passed in, then use it to initialize
        // the stop array.  The values are 1 less than the size.
        //
        stopArray = new index_type[axesCount];
        dataMaxIndx = stopArray;

        if (axisSizes != NULL)
        {
            unsigned int i;
            for (i = 0; i < axesCount; i++)
                stopArray[i] = axisSizes[i] - 1;
        }
        else
            memset(stopArray, 0, axesCount*sizeof(index_type));

        Reset();
    }

// THIS WILL POINT TO THE SAME DATA MEMORY
//
    GridExtents(const GridExtents<T>& src)
        : axesCount(0),
          startArray(NULL),
          stopArray(NULL),
          dataMinIndx(NULL),
          axisElementCount(NULL),
          axisElementOffset(NULL),
          dataPtr(NULL)
    {
        *this = src;
    }

// THIS WILL POINT TO THE SAME DATA MEMORY
//
    GridExtents<T>& operator=(const GridExtents<T>& src)
    {
        //
        // Copy the axesCount
        //
        axesCount = src.axesCount;

        elementSize = src.elementSize;

        //
        // Copy the start array
        //
        delete[] startArray;
        startArray = new index_type[axesCount];

        if(src.startArray != NULL)
            memcpy(startArray, src.startArray, axesCount*sizeof(index_type));
        else
            memset(startArray, 0, axesCount*sizeof(index_type));

        //
        // Copy the stop array
        //
        delete[] stopArray;
        stopArray = new index_type[axesCount];

        if (src.stopArray != NULL)
            memcpy(stopArray, src.stopArray, axesCount*sizeof(index_type));
        else
            memset(stopArray, 0, axesCount*sizeof(index_type));

        //
        // If the source data Min/Max Index arrays are different than
        // the start stop arrays, then we must duplicate them.
        //
        if (src.dataMinIndx != src.startArray)
        {
            delete[] dataMinIndx;
            dataMinIndx = new index_type[axesCount];
            memcpy(dataMinIndx, src.dataMinIndx, axesCount*sizeof(index_type));
        }
        else
            dataMinIndx = startArray;

        if (src.dataMaxIndx != src.stopArray)
        {
            delete[] dataMaxIndx;
            dataMaxIndx = new index_type[axesCount];
            memcpy(dataMaxIndx, src.dataMaxIndx, axesCount*sizeof(index_type));
        }
        else
            dataMaxIndx = stopArray;

        //
        // Point to the same data memory.
        //
        dataPtr = src.dataPtr;

        Reset();

        //
        // Return this.
        //
        return *this;
    }

    virtual ~GridExtents()
    {
        FreeMem();
    }


      //
      // These are some helpful methods.
      //
    GridExtentsList<T> *SubDivide(index_type* numDivisions);
    GridExtentsList<T> *SubDivideByRunLengthDataSize
                               (unsigned int& maxElements);
    GridExtentsList<T> *SubDivideByRunLengthElementCount
                               (unsigned int& maxElements);


    const iterator     &begin() const { return beginIter; }
    const iterator     &end() const   { return endIter; }

    T                  *GetDataPointer() const { return (T*)dataPtr; }
    unsigned int        GetAxesCount() const { return axesCount; }
    index_type          GetAxisLength(int axisNum) const
           {
               return stopArray[axisNum] - startArray[axisNum] + 1;
           }
    index_type          GetStart(int axisNum) const
                               { return startArray[axisNum]; }
    index_type          GetStop(int axisNum) const
                               { return stopArray[axisNum]; }
    const index_type   *GetStarts() const { return startArray; }
    const index_type   *GetStops() const { return stopArray; }
    unsigned int        GetElementSize() const { return elementSize; }
    unsigned int        GetAxisElementCount(int axisNum) const
                               {
                                   return axisElementCount[axisNum];
                               }
    unsigned int        GetElementCount() const
                               {
                                   return axisElementCount[0];
                               }

    unsigned int        GetDataSize() const
                               { return GetElementCount() * GetElementSize(); }

    void                SetStart(int axisNum, index_type val)
                               {startArray[axisNum] = val;}
    void                SetStop(int axisNum, index_type val)
                               {stopArray[axisNum] = val;}
    void                SetDataPointer(pointer data)
                               {
                                   dataPtr = data;
                                   ComputeBeginEnd();
                               }

    void                SetElementSize(unsigned int newSize)
                               {
                                   elementSize = newSize;
                                   ComputeBeginEnd();
                               }

    bool         Contains(const GridExtents<T>& extB) const;
    bool         EqualExtents(const GridExtents<T>& extB) const;
    bool         Intersects(const GridExtents<T>& extB) const
                               {
                                   return Intersect(*this,extB);
                               }
#if 0
    friend bool         Intersect
                               (
                                   const GridExtents<T>& extA,
                                   const GridExtents<T>& extB
                               );
    friend bool         Intersect
                               (
                                   const GridExtents<T>& extA,
                                   const GridExtents<T>& extB
                               )
                               {
                                   return extA.Intersects(extB);
                               }
    friend GridExtents<T> *Intersection
                                  (
                                      const GridExtents<T>& extA,
                                      const GridExtents<T>& extB
                                  );
#endif

    bool               TransferData
                              (
                                  const GridExtents<T>& srcExt,
                                  index_type  cellOffset,
                                  index_type  srcCellOffset
                              );

    void            Print(FILE *f_ptr) const;
    void            Reset()
                                  {
                                      ComputeElementCounts();
                                      ComputeElementOffsets();
                                      ComputeBeginEnd();
                                  }

    unsigned int DataIndex(const index_type* indxArray) const
              {
                  unsigned int i, offsetIndx = 0;

                  for(i=0; i < axesCount; i++)
                     offsetIndx += axisElementOffset[i + 1] *
                                              (indxArray[i] - dataMinIndx[i]);
                  return offsetIndx;
              }

    T* DataOffset(const index_type* indxArray)        const
              {
                  return (T*)((unsigned char*)dataPtr +
                              (DataIndex(indxArray) * elementSize));
              }

  protected:
    void SubDivideAxis(index_type axisIndx, index_type numDivisions,
                       list_type* extList);

    void ComputeBeginEnd()
                {
                    beginIter = iterator(this, startArray);
                    endIter   = iterator(this, stopArray);
                    ++endIter;
                }

    void ComputeElementCounts()
                {
                    if (axisElementCount == NULL)
                        axisElementCount = new unsigned int[axesCount + 1];

                    axisElementCount[axesCount] = 1;

                    int i;
                    for (i = axesCount - 1; i >=0; --i)
                        axisElementCount[i] = axisElementCount[i + 1] *
                                              GetAxisLength(i);
                }

    void ComputeElementOffsets()
                {
                    if (axisElementOffset == NULL)
                        axisElementOffset = new unsigned int[axesCount + 1];

                    axisElementOffset[axesCount] = 1;

                    int i;
                    for (i = axesCount - 1; i >=0; --i)
                        axisElementOffset[i] = axisElementOffset[i + 1] *
                            (dataMaxIndx[i] - dataMinIndx[i] + 1);
                }

    void FreeMem()
                {
                    if (dataMinIndx != NULL)
                    {
                        if (dataMinIndx != startArray)
                        {
                            delete[] dataMinIndx;
                        }
                        dataMinIndx = NULL;
                    }

                    if (dataMaxIndx != NULL)
                    {
                        if (dataMaxIndx != stopArray)
                        {
                            delete[] dataMaxIndx;
                        }
                        dataMaxIndx = NULL;
                    }

                    if (startArray != NULL)
                    {
                        delete[] startArray;
                        startArray = NULL;
                    }

                    if (stopArray != NULL)
                    {
                        delete[] stopArray;
                        stopArray = NULL;
                    }

                    if (axisElementCount != NULL)
                        delete[] axisElementCount;
                    axisElementCount = NULL;

                    if (axisElementOffset != NULL)
                        delete[] axisElementOffset;
                    axisElementOffset = NULL;
                }

  public:
    //
    // The next is a template derived classed for iterating across the
    // contents of the grid.
    //
    class iterator //: public bidirectional_iterator<T, difference_type>
    {
        friend class GridExtents<T>;

      public:
        iterator() : grid(NULL), currElement(NULL), currIndx(NULL) {}

        iterator(GridExtents<T>* initialGrid,
                                        const index_type *valArray = NULL)
            : grid(initialGrid)
               {
                   currIndx = new index_type[grid->GetAxesCount()];
                   SetCurrIndx(valArray);
               }

        virtual ~iterator()
                {
                    delete[] currIndx;
                }


        iterator(const iterator& iter)
            : grid(iter.grid),
              currElement(NULL),
              currIndx(NULL)
               {
                   *this = iter;
               }

        iterator& operator=(const iterator& iter)
               {
                   grid = iter.grid;
                   if (currIndx != NULL)
                       delete[] currIndx;
                   currIndx = new index_type[grid->GetAxesCount()];
                   SetCurrIndx(iter.currIndx);
                   currElement = iter.currElement;
                   return *this;
               }

      protected:
        bool AtEnd() const
                    {
                        //
                        // The definition of the end of the iterator is when
                        // the index for the most major axes (the first in out
                        // lists) is larger then the stop value.
                        //
                        return (*currIndx > *(grid->stopArray));
                    }


      public:
        const index_type *GetCurrIndx() { return currIndx; }
        void SetCurrIndx(const index_type *valArray)
                    {
                        memcpy(currIndx, valArray, grid->GetAxesCount() *
                               sizeof(index_type));

// can we do this easier when just incrementing
                        currElement = grid->DataOffset(currIndx);
                    }

        bool operator==(const iterator& iter) const
                    {
                        //
                        // We could loop through the currIndx array and check
                        // the values, but for now, we'll rely on the current
                        // element pointers being the same. If the two
                        // iterators don't point to the same grid, then they
                        // aren't equal.
                        //
#if 0
                        bool        retVal;
                        if (grid != iter.grid)
                        {
                            retVal = false;
                        }
                        else
                        {
                            if (AtEnd() && iter.AtEnd())
                                retVal = true;
                            else
                            {
                                if (currElement == iter.currElement)
                                    retVal = true;
                                else
                                    retVal = false;
                            }
                        }
                        return retVal;
#else
                        return (grid != iter.grid ? false :
                                (AtEnd() && iter.AtEnd() ? true :
                                (currElement == iter.currElement)));
#endif
                    }

        bool operator!=(const iterator& iter) const
                    {
                        return (*this == iter ? false : true);
                    }

        reference operator*()
                    {
                        return *((T*)currElement);
                    }

        iterator& operator++()
                    {
                        int i;
                        int lastIndx = grid->axesCount - 1;

                        //
                        // Don't do anything if we are already at the end of
                        // our rope.
                        //
                        if (!AtEnd())
                        {
                            //
                            // First, increment the current element pointer and
                            // the current index of the last (most frequent)
                            // axes.
                            //
                            currElement = ((unsigned char*)currElement) +
                                          grid->GetElementSize();
                            currIndx[lastIndx]++;

                            //
                            // Now loop through the axes and "carry over" the
                            // current element pointer in axis indices.
                            //
                            for(i = lastIndx; ((i >=0) && !AtEnd()); i--)
                            {
                                //
                                // If the current axis' index is beyond the
                                // stop for this axis, then reset the index to
                                // the axis' start, and continue the loop,
                                // which will increment the next axis' index.
                                // Otherwise, just break out of the loop,
                                // because we're done.
                                //
                                // When resetting the axis index we must also
                                // reset the current element pointer.  We do
                                // this by computing the number of elements
                                // to "skip".  First, we skip backwards the
                                // number of elements covered by this axis
                                // (start to stop).  Then we skip forward the
                                // number of element covered by this axis in
                                // the data.
                                //
                                if (currIndx[i] > grid->stopArray[i])
                                {
                                    int                skip;
                                    currIndx[i] = grid->startArray[i];
                                    skip = ((int)grid->GetAxisLength(i) * -1)
                                           * grid->axisElementOffset[i + 1];
                                    skip += grid->axisElementOffset[i];
                                    currElement = ((unsigned char*)currElement)
                                              + (skip * grid->GetElementSize());

                                    //
                                    // If this is any axis other than the 1st,
                                    // then we must increment the index of the
                                    // next axis (from most major to least).
                                    //
                                    if (i > 0)
                                        currIndx[i - 1]++;
                                }
                                else
                                    break;
                            }
                        }

#if 0
                        if (currElement != grid->DataOffset(currIndx))
                        {
                            fprintf(stderr, "Oops the offsets are different:"\
                                    " %08x vs. %08x\n", currElement,
                                    grid->DataOffset(currIndx));
                        }
#endif
                        return *this;
                    }

        iterator operator++(int)
                        {
                            iterator tmp(*this);
                            ++*this;
                            return tmp;
                        }

      private:
        GridExtents<T> *grid;
        void           *currElement;
        index_type     *currIndx;
    };

  protected:
    void         *dataPtr;
    unsigned int  elementSize;
    unsigned int  axesCount;
    index_type   *startArray;
    index_type   *stopArray;
    unsigned int *axisElementCount;
    unsigned int *axisElementOffset;
    index_type   *dataMinIndx;
    index_type   *dataMaxIndx;
    iterator      beginIter;
    iterator      endIter;
};


template <class T> class GridExtentsList : public list < GridExtents<T> >
{};

template <class T> class GridSubExtents : public GridExtents<T>
{
  public:

    GridSubExtents(const GridExtents<T>& parentExt,
                          const GridExtents<T>& subExt)
    : parent(parentExt),
      GridExtents<T>(subExt)
    {
        //
        // First, check to see that the parent contains the sub extents.
        //
        if (parent.Contains(*this) == false)
        {
            fprintf(stderr, "WARNING ! - GridExtentsIterator constructor passed"\
                    " a sub-extents that isn't contained in the parent extents\n");
            fprintf(stderr, "            Further behavior is undefined !\n");
        }

        //
        // Now, copy the dataMinIndx from the parent.
        // For this subclass, the start/stop's are now the same as the subExtents,
        // but the dataMin/MaxIndx are that of the parent.  This is what gives us
        // the proper behavior in the iterator.
        //
#if defined (STF_STL_TYPE)
        this->dataMinIndx = new unsigned int[this->axesCount];
        memcpy(this->dataMinIndx, parent.dataMinIndx,
               this->axesCount*sizeof(unsigned int));
        this->dataMaxIndx = new unsigned int[this->axesCount];
        memcpy(this->dataMaxIndx, parent.dataMaxIndx,
               this->axesCount*sizeof(unsigned int));
#else
        dataMinIndx = new index_type[axesCount];
        memcpy(dataMinIndx, parent.dataMinIndx, axesCount*sizeof(index_type));
        dataMaxIndx = new index_type[axesCount];
        memcpy(dataMaxIndx, parent.dataMaxIndx, axesCount*sizeof(index_type));
#endif


    //
    // Set the data pointer to that of the parent and set the size to the size of
    // the parent.
    //
        SetDataPointer(parent.GetDataPointer());
        SetElementSize(parent.GetElementSize());
    }

  private:
    const GridExtents<T>&        parent;
};


template <class T> void
GridExtents<T>::Print(FILE *f_ptr) const
{
    fprintf(f_ptr, "start/stop's: ");
    for (unsigned int i = 0; i < axesCount; i++)
        fprintf(f_ptr, " (%u, %u)", startArray[i], stopArray[i]);

    fprintf(f_ptr, "\n");
}


template < class T >
inline const T&
minimum(const T& a, const T& b)
{
    return (a < b ? a : b);
}

template < class T >
inline const T&
maximum(const T& a, const T& b)
{
    return (a > b ? a : b);
}

inline int
iceil(int a, int b)
{
    int                c;
    c = a / b;
    if ((a % b) != 0)
        c++;

    return c;
}


//-----------------------------------------------------------------------------
//
// This method subdivides each extents in the extList list along the axisIndx
// axis. The number of subdivisions to make is indicated by numDivisions.
//
// The process is to iterate across the extList.
// For each extents in the list, we compute the number of elements along the
// axis, which will result in the requested number of divisions.  We then
// create numDivisions new subextents.  The starts and stops are computed
// incrementally so that each subextents contains the computed number of
// elements.  The last subextents will be smaller than the rest if the number
// of divisions does not result in a whole number of elements.  Each of the
// original extents are then removed.  This work is done "in-place" so that the
// relative order of the extents is preserved.
//
//-----------------------------------------------------------------------------
 template <class T> void
 GridExtents<T>::SubDivideAxis(index_type axisIndx, index_type numDivisions,
                               list_type* extList)
 {
#if defined (STF_STL_TYPE)
     typename list_type::iterator                extIter;
     typename list_type::iterator                tmpIter;
#else
     list_type::iterator                extIter;
     list_type::iterator                tmpIter;
#endif

     index_type                        numElements;
     index_type                        newStart;
     index_type                        newStop;

     // Start the iteration across the list.  Only do all this if the number of
     // divisions is greater than 1.
     //
     if (numDivisions > 1)
     {
         for(extIter = extList->begin(); extIter != extList->end();)//extIter++)
         {
             // Create a local reference to the current extents of the iterator.
             // Also, go ahead and instantiate an extents for the subdivision.
             // We will reuse the extents, only modifying the start/stops when
             // pushing it on the list.
             //
             const GridExtents<T>&        currExt = (*extIter);
             GridExtents<T>                newExt(currExt);

 #ifdef STF_DEBUG
             fprintf(stderr, "     Replacing extents - ");
             currExt.Print(stderr);
             fprintf(stderr, "     With %u new sub-extents:\n", numDivisions);
 #endif

         // The number of elements along this axis for each sub extents is the
         // next whole number larger than the number of elements in the source
         // axis, divided by the number of subdivisions.
         //
             numElements = iceil(currExt.GetAxisLength(axisIndx), numDivisions);

             // Initialize the newStarts and the newStops before creating the
             // new subextents.
             //
             newStart = currExt.startArray[axisIndx];
             newStop  = currExt.stopArray[axisIndx];

         // Create numDivisions subextents.  Each subextents will contain
         // numElements along the desired axis, with the possible exception
         // of the last subextents.  It may contain fewer if the number of
         // division did not result in a whole number of elements.
         //
             for(index_type i=0; i < numDivisions; i++)
             {
                 // The stop value for this axis is the start value plus the
                 // number of elements minus one.  If the stop value is beyond
                 // the stop value for the current extents, then clamp it to the
                 // current extents stop value.
                 //
                 newStop = newStart + numElements - 1;
                 if (newStop > currExt.stopArray[axisIndx])
                     newStop = currExt.stopArray[axisIndx];

                 //
                 // Set the start stops of the new extents.
                 //
                 newExt.SetStart(axisIndx, newStart);
                 newExt.SetStop(axisIndx, newStop);
                 newExt.Reset();

 #ifdef STF_DEBUG
                 fprintf(stderr, "         ");
                 newExt.Print(stderr);
 #endif

                 //
                 // insert the new extents in front of the current extents.
                 //
                 extList->insert(extIter, newExt);

                 //
                 // The next start value for this axis while be the current
                 // stop value plus one.
                 //
                 newStart = newStop + 1;
             }

             //
             // Remove the current extents since it has been "replaced" by the
             // subdivided extents.
             //
             tmpIter = extIter;
             extIter++;

             extList->erase(tmpIter);

         }
     }
 }


//------------------------------------------------------------------------------
//
// METHOD: SubDivide
//
//   Creates a list of subextents from the "this" extents.  The subextents
//   created represent subdivisions of this extents.  The number of
//   subdivisions along each axis is given by the numDivisions array.
//
//   The process is to first create a copy of this extents and place it on the
//   list. We then iterate across the axes, and for each one we call the
//   private SubDivideAxis method to do the hard work.
//
//------------------------------------------------------------------------------
 #if defined (STF_STL_TYPE)
 template <class T> GridExtentsList<T>*
 #else
 template <class T> GridExtents<T>::list_type*
 #endif
 GridExtents<T>::SubDivide(index_type* numDivisions)
 {
     list_type *extList = new list_type;
     unsigned int i;

     // Push a copy of this extents on the list.
     //
     extList->push_front(*this);

     // Iterate across the axes and call SubDivideAxis.
     //
     for (i = 0; i < axesCount; i++)
     {
         SubDivideAxis(i, numDivisions[i], extList);
     }

     return extList;
 }


//------------------------------------------------------------------------------
//
// METHOD: SubDivideByRunLengthDataSize
//
//   Creates a list of subextents which are the result of sub-dividing "this"
//   extents to the point that no more the "maxDataSize" bytes of memory is
//   required by any one subextents.
//
//   maxDataSize is an in/out parameter in order to return to the caller the
//   real maximum extents size in bytes.
//
//   The process is to compute the maximum number of elements that will fit
//   within the data size.  Then we call SubDivideByRunLengthElementCount using
//   this number to do the real work.  Finally, we use the maxElements that
//   comes back from SubDivideByRunLengthElementCount to compute the real
//   memory requirement.
//
//------------------------------------------------------------------------------
 #if defined (STF_STL_TYPE)
 template <class T> GridExtentsList<T>*
 #else
 template <class T> GridExtents<T>::list_type*
 #endif
 GridExtents<T>::SubDivideByRunLengthDataSize(unsigned int& maxDataSize)
 {
     unsigned int  maxElements = maximum(maxDataSize / GetElementSize(), 1U);
     list_type    *returnList;

     returnList = SubDivideByRunLengthElementCount(maxElements);

     maxDataSize = maxElements * GetElementSize();

     return returnList;
 }


//------------------------------------------------------------------------------
//
// METHOD: SubDivideByRunLengthElementCount
//
//   Creates a list of subextents which are the result of sub-dividing "this"
//   extents to the point that no more the "maxElements" elements are in any
//   one subextents.  maxElements is an in/out parameter in order to return to
//   the caller the real maximum number of elements.
//
//   The process:
//   1) iterate from most major axis (first in the list) to the least major
//      axis until we find the first axis with fewer elements then the max
//      requested.  The axis preceeding it will be the last to be subdivided.
//   2) create create the "subdivide" array that indicates the number of times
//      to subdivide each axis.  The axes "above" the last subdived axis will
//      be subdivided once per element along the axis.  Those below it won't
//      get subdivided at all.
//
//------------------------------------------------------------------------------
 #if defined (STF_STL_TYPE)
 template <class T> GridExtentsList<T>*
 #else
 template <class T> GridExtents<T>::list_type*
 #endif
 GridExtents<T>::SubDivideByRunLengthElementCount(unsigned int& maxElements)
 {
     //
     // Iterate through the axes and find the first one which "fits" into the
     // maxElements.
     //
     // The next to last axis evaluated (i - 1 after the loop) is the last to
     // be subdivided.
     //
     unsigned int i;
     for (i = 0; (i < axesCount) && (axisElementCount[i] > maxElements); ++i);
     int  lastDivision = i - 1;

     if (lastDivision < 0)
         lastDivision = 0;

     //
     // Create an array to indicate the number of subdivision to be created
     // along each axis. Initialize the first part (up to but not including the
     // ith element) with the number of elements along the axis.  The ith
     // element is next  whole number larger than the number of elements divided
     // by the maxElements.
     //
     index_type*                subdivisions = new index_type[axesCount];

     for (i = 0; (int)i < lastDivision; i++)
         subdivisions[i] = GetAxisLength(i);

     index_type                proposedElements;

     proposedElements = maxElements / axisElementCount[lastDivision + 1];
     if (proposedElements > GetAxisLength(lastDivision))
         proposedElements = GetAxisLength(lastDivision);

     subdivisions[lastDivision] = iceil(GetAxisLength(lastDivision),
                                        proposedElements);

     for (i = lastDivision + 1; i < axesCount; i++)
         subdivisions[i] = 1;

     //
     // Now call the SubDivide method to create the subextents based on the
     // subdivisions array.
     //
     list_type  *returnList;
     returnList = SubDivide(subdivisions);

     //
     // Free up the subdivisions list.
     //
     delete[] subdivisions;

     //
     // Before returning, determin the maximum number of elements in the
     // extents list.
     //
     unsigned int        realMax = 0;
 #if defined (STF_STL_TYPE)
     typename list_type::iterator        extIter;
 #else
     list_type::iterator        extIter;
 #endif

     for (extIter=returnList->begin(); extIter != returnList->end(); ++extIter)
         realMax = maximum(realMax, (*extIter).GetElementCount());

     maxElements = realMax;

     //
     // Return the list.
     //
     return returnList;
 }



 template <class T> bool
 GridExtents<T>::EqualExtents(const GridExtents<T>& extB) const
 {
     if( axesCount != extB.axesCount )
         return false;
     //
     unsigned short  i;
     for( i=0 ; i<axesCount ; i++ )
     {
        if( (startArray[i] != extB.startArray[i]) ||
            (stopArray[i]  != extB.stopArray[i]) )
             return false;
     }
     return true;
 }

 template <class T> bool
 GridExtents<T>::Contains(const GridExtents<T>& extB) const
 {
     //
     // Start by making sure both extents have the same number of axes.
     // If not, then the grids can't overlap.
     //
     if (axesCount != extB.axesCount)
         return false;
     //
     // For each axis, ...
     //
     unsigned short                i;
     for (i = 0; i < axesCount; i++)
     {
         //
         // All of this extents' starts must be less than B's respective starts.
         // Similarly, all of this extents' stops must be greater than B's.
         //
         if ((startArray[i] > extB.startArray[i]) ||
             (stopArray[i] < extB.stopArray[i]))
             return false;
     }
     return true;
 }


template <class T1, class T2> inline bool
Intersect(const GridExtents<T1>& extA, const GridExtents<T2>& extB)
{
    bool        returnVal = true;
    //
    // Our definition of intersection is that the start stop ranges have
    // some overlap.  If one extents has more axes than the other, then
    // the comparison is done only over the lesser number of axes.  The
    // remaining axes of the extents with more axes are thought to lie
    // within the the one with fewer.
    //
    int minAxesCount = minimum(extA.GetAxesCount(), extB.GetAxesCount());

    //
    // For each axis, ...
    //
    unsigned short                i;
    for (i = 0; (returnVal != false) && (i < minAxesCount); i++)
    {
        //
        // First check to see if there is any intersection at all between
        // these axes.  All axes must have some overlap.  If one does not,
        // then we stop.
        //
        if ((extA.GetStart(i) > extB.GetStop(i)) ||
            (extB.GetStart(i) > extA.GetStop(i)))
            returnVal = false;
    }

    return returnVal;
}

template <class T1, class T2> inline GridExtents<T1>*
Intersection(const GridExtents<T1>& extA, const GridExtents<T2>& extB)
{
    GridExtents<T1>*                extC = NULL;
    //
    // Start by making sure the extents actually intersect
    //
    if (Intersect(extA, extB) == true)
    {
        //
        // Out definition of intersection is that the start stop ranges have
        // some overlap.  If one extents has more axes than the other, then
        // the comparison is done only over the lesser number of axes.  The
        // remaining axes of the extents with more axes are thought to lie
        // within the the one with fewer.
        //
        int minAxesCount = minimum(extA.GetAxesCount(), extB.GetAxesCount());


        //
        // Create a new extents.  The number of axes should be the larger of
        // the 2 axes.  What we do is actually copy the extents with the larger
        // number of axes.  The way, later when we compute the intersection, it
        // will only need to be done on the match axes.
        //

        if (extA.GetAxesCount() > extB.GetAxesCount())
            extC = new GridExtents<T1>(extA);
        else
            extC = new GridExtents<T1>(extB.GetAxesCount(), extB.GetStarts(),
                                       extB.GetStops());

        //
        // Null out the data pointer of the new extents.
        //
        extC->SetDataPointer(NULL);

        //
        // Iterate over the matching axes and set the resulting starts and
        // stops.
        //
        int            i;
        for (i = 0; i < minAxesCount; i++)
        {
            extC->SetStart(i, maximum(extA.GetStart(i), extB.GetStart(i)));
            extC->SetStop(i, minimum(extA.GetStop(i), extB.GetStop(i)));
         }
        extC->Reset();
    }
    return extC;
}

// copy the data as efficiently as possible from the data in the srcExt
//
// (assume that the exents Intersect, that the element size is the same,
// and that the dataPtr's are not null.)
//
//
 template <class T> bool
 GridExtents<T>::TransferData( const GridExtents<T>& srcExt,
                 index_type  cellOffset, index_type srcCellOffset )
 {
    if( !Intersect( *this, srcExt ) )
    {
       fprintf(stderr, "GridExtents: TransferData: grids don't intersect!");
       return false;
    }

    // the beginning and ending index's of the intersection between the
    // grid and src, and a loop indx for them.
    // (these can be thought of as coordinates in the N dimension space
    // created by N axes.)
    //
    index_type *beginIndx, *endIndx, *indx;

    // the lowest order axes (dimension) in the grid; the fastest varying.
    int i, lastIndx;

    // a flag indicating that the data has contiguous data sections.
    // if true we attempt to 'reduce' the dimensions in the grid that we
    // process by finding all the lower order dimensions (axes) that are
    // the same size in the data and in the intersection.
    //
    bool cont_data = ( cellOffset == 0 && srcCellOffset == 0 ? true : false );
    bool reducing_grid = cont_data;

    // set the element size to be copied to be the smaller
    // of this grid's elementSize and the source grid's elementSize.
    //
    unsigned int element_size = (elementSize < srcExt.elementSize ?
                                 elementSize : srcExt.elementSize);

    // find the begin/end indexes of the intersection to be copied.
    //
    beginIndx = new index_type[ axesCount ];
    endIndx   = new index_type[ axesCount ];
    indx      = new index_type[ axesCount ];

    lastIndx = axesCount - 1;

    for( i=axesCount-1 ; i >= 0; i-- )
    {
       beginIndx[i] = maximum( startArray[i], srcExt.startArray[i] );
       endIndx[i]   = minimum( stopArray[i], srcExt.stopArray[i] );
       indx[i]      = beginIndx[i];
    }

    // we can reduce the grid by processing axes that are the same for
    // both grids. This takes advantage of the fact that the data will
    // be contiguous when copying lower order dimensions.
    //
    if( cont_data )
    {
       for( i=axesCount-1 ;
            lastIndx > 0 && reducing_grid ;
            i-- )
       {
          if( startArray[i]  == dataMinIndx[i] &&
              startArray[i]  == srcExt.startArray[i] &&
              dataMinIndx[i] == srcExt.dataMinIndx[i] &&
              stopArray[i]   == dataMaxIndx[i] &&
              stopArray[i]   == srcExt.stopArray[i] &&
              dataMaxIndx[i] == srcExt.dataMaxIndx[i]  )
          {
             lastIndx--;
             element_size *= (dataMaxIndx[i]-dataMinIndx[i]+1);
          }
          else
          {
             // once a discontinuity is found we have to stop looking for
             // contiguous data.
             //
             reducing_grid = false;
          }

       }

       // the lowest (reduced) dimension must have its elements contiguous
       // even if they don't span the whole axis so add this to the
       // contiguous data size. the transfer algorithm for cont_data will
       // handle this lowest dimension differently than for non-cont data.
       //
       element_size *= (endIndx[lastIndx]-beginIndx[lastIndx]+1);
    }

    // pointers to the elements in the grid being copied (or to the
    // beginning of a contiguous section of elements.)
    //
    T *dataOffset, *srcDataOffset;
    bool  carry=true, done=false;

    // Use different algorithms for copying continuous and non-cont data.
    // With both algorithms we keep track of our position in the data by
    // using indx to step thru all the axis that haven't been reduced.
    // (The number of axis is variable so we can't very well step thru
    // them.)
    //
    if( !cont_data )
    {
       // the data is not continous so we have to copy each element
       // individually. (lastIndx will always be the lowest order axis;
       // fastest varying; axixCount-1)
       //
       while( !done )
       {
          // find the location in the data and source data for this indx and copy
          // 1 element.
          //
          dataOffset = DataOffset( indx ) + cellOffset;
          srcDataOffset = srcExt.DataOffset( indx ) + srcCellOffset;

          memcpy( dataOffset, srcDataOffset, element_size );

          // increment indx and determine if we're at the end
          //
          indx[lastIndx]++;

          for( i=lastIndx, carry=true ; i >= 0 && carry ; i-- )
          {
             if( indx[i] > endIndx[i] )
             {
                carry = true;
                indx[i] = beginIndx[i];

                if( i == 0 )
                   done = true;
                else
                   indx[i-1]++;
             }
          }
       }
    }
    else // if the data has continuous segments
    {
       // loop thru a reduced set of axis (dimensions). (lastIndx may be
       // less than axisCount-1)
       //
       while( !done )
       {
          // find the location in the data and source data for this indx and copy
          // 1 element.
          //
          dataOffset = DataOffset( indx );           // cell offsets are 0
          srcDataOffset = srcExt.DataOffset( indx );

          memcpy( dataOffset, srcDataOffset, element_size );

          // the low dimension (lastIndx) is accounted for in the element_size
          // so here we skip over it instead of stepping thru it.
          //
          indx[lastIndx] += (endIndx[lastIndx]-beginIndx[lastIndx]+1);

          for( i=lastIndx, carry=true ; i >= 0 && carry ; i-- )
          {
             if( indx[i] > endIndx[i] )
             {
                carry = true;
                indx[i] = beginIndx[i];

                if( i == 0 )
                   done = true;
                else
                   indx[i-1]++;
             }
          }
       }
    }

    delete[] beginIndx;
    delete[] endIndx;
    delete[] indx;

    return true;
 }


#endif // _GRID_EXTENTS_HPP_INCLUDED
