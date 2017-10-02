// SEDRIS Level 0 Read API
//
// Produced by: The SEDRIS Team
//
// FILE:        se_lists.hpp
//
// PROGRAMMERS: Robert D'Urso (SAIC), Howard Lu (SAIC), Bill Horan (SAIC)
//
// DESCRIPTION: Header for for singly linked list and iterator templates
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

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

#ifndef _SE_LISTS_HPP_INCLUDED
#define _SE_LISTS_HPP_INCLUDED

#include <stdio.h>
#include <stdlib.h>

template<class T>
class SEDRIS_List_Elem
{
  public:
    // Creation
    inline SEDRIS_List_Elem(const T& elem) : next(NULL), elem_value(elem) {}

    // Examination
    inline const T& get_elem_value() const {return elem_value;}
    inline SEDRIS_List_Elem<T>* next_elem() const {return next;}

    // Modification
    inline void  set_next_elem(SEDRIS_List_Elem<T> *new_next)
                 {next = new_next;}

  private:
    // copy constructor
    inline SEDRIS_List_Elem(const SEDRIS_List_Elem<T>&);

    // assignment
    inline SEDRIS_List_Elem<T>& operator= (const SEDRIS_List_Elem<T>&);

    SEDRIS_List_Elem<T> *next;
    T                    elem_value;
};

template<class T> class SEDRIS_List;

template<class T>
class SEDRIS_Iterator
{
  public:
    // Creation
    inline SEDRIS_Iterator() : list(NULL), curr_elem(NULL) {}
    inline SEDRIS_Iterator(const SEDRIS_List<T> *List,
                           const SEDRIS_List_Elem<T> *Curr_elem)
        : list(List), curr_elem(Curr_elem) {}

    // Iterate (with for) over a list with these member functions
    //
    // For example, assume "iter" is an object of type SEDRIS_Iterator -
    //
    // for (iter.reset(); iter.isValid(); iter.next())
    // {
    //     T elem = iter.item();
    //     ...
    // }
    //

    inline void reset(void)         {curr_elem = list->pFirst();}
    inline int  isValid(void) const {return curr_elem != NULL;}
    inline void next(void)          {curr_elem = curr_elem->next_elem();}

    // Return current item from iteration
    inline const T& item() const {return curr_elem->get_elem_value();}
    inline const SEDRIS_List<T>* getList() const { return list; }
    inline const SEDRIS_List_Elem<T>* getCurrElem() const { return curr_elem; }

  private:
    // Note that the copy constructor and assignment operator are
    // currently using the default definitions.  If the private
    // elements become more than pointers to objects, this may
    // need to change.

    const SEDRIS_List<T> *list;
    const SEDRIS_List_Elem<T> *curr_elem;
};

template<class T>
class SEDRIS_List
{
  public:
    inline SEDRIS_List() : head(NULL), tail(NULL), population(0) {}
    inline virtual ~SEDRIS_List() {removeAll();}

    // Return an iterator
    inline SEDRIS_Iterator<T> items(void) const
                            {return SEDRIS_Iterator<T>(this, head);}

    // Return a pointer to the first element
    inline SEDRIS_List_Elem<T> *pFirst(void) const {return head;}

    // Return a reference to the first element
    inline const T& first(void) const
           {
               if (population==0)
               {
                   fprintf(stderr,"Fatal Error - get first() of empty list\n");
                   abort();
               }
               return head->get_elem_value();
           }

    // Return a reference to the first element and remove it from list
    inline T removeFirst(void);

    // Return a reference to the nth element (first element is element 0)
    inline const T& item(long n) const;

    // Return the number of elements currently in the list
    inline long count(void) const {return population;}

    // Remove all elements from the list
    inline void removeAll(void);

    // Remove the nth element from the list
    inline void removeItem(long n);

    // Remove the element pointer to by the iterator from the list
    inline SEDRIS_Iterator<T> removeItem(const SEDRIS_Iterator<T>& iter);

    // Add an element to the beginning of the list
    inline void addFirst(const T& elem);

    // Add an element to the end of the list
    inline void addLast(const T& elem);

    // Add an element after the nth element of the list, (first element is 0
    // and negative n places elem on front of list
    inline void addAfter(long n, const T& elem);

  private:
    inline SEDRIS_List(const SEDRIS_List<T>&);   // copy constructor
    inline SEDRIS_List<T>& operator= (const SEDRIS_List<T>&);   // assignment

    SEDRIS_List_Elem<T> *head;
    SEDRIS_List_Elem<T> *tail;
    long                 population;
};

template<class T>
T SEDRIS_List<T>::removeFirst()
{
    T elem;
    if (population == 0)
    {
        fprintf(stderr,"Fatal Error - removeFirst() of empty list\n");
        abort();
    }
    else
    {
        SEDRIS_List_Elem<T> *tmp = head->next_elem();
        elem = head->get_elem_value();
        delete head;
        head = tmp;
        population--;
        if (population == 0) head = tail = NULL;
    }
    return elem;
}

template<class T>
const T& SEDRIS_List<T>::item(long n) const
{
    SEDRIS_List_Elem<T> *tmp;

    if (population < n || population == 0)
    {
        fprintf(stderr,"Fatal Error - asked for item %i of a list with " \
                "only % items\n", (int) n, (int) population);
        abort();
    }
    tmp = head;

    for (long i=0; i<n; ++i)
        tmp = tmp->next_elem();

    return tmp->get_elem_value();
}

template<class T>
void SEDRIS_List<T>::removeItem(long n)
{
    SEDRIS_List_Elem<T> *tmp, *prev;

    if (population < n || population == 0)
    {
        fprintf(stderr,"Fatal Error - asked to remove item %i of a list with" \
                " only % items\n", (int) n, (int) population);
        abort();
    }
    prev = NULL;
    tmp  = head;

    for (long i=0; i<n; ++i)
    {
        prev = tmp;
        tmp  = tmp->next_elem();
    }

    if (prev)
        prev->set_next_elem(tmp->next_elem());
    else // since prev == NULL, tmp == head
        head = head->next_elem();

    if (tmp == tail)
        tail = prev;

    --population;

    delete tmp;
}

template<class T>
SEDRIS_Iterator<T> SEDRIS_List<T>::removeItem
(
    const SEDRIS_Iterator<T>& iter
)
{
    SEDRIS_List_Elem<T> *tmp, *prev;
    bool                 found = false;

    if (iter.getList() != this)
    {
        fprintf(stderr,"Fatal Error - asked to remove an item using an "\
                "iterator from a different list\n");
        abort();
    }
    prev = NULL;
    tmp  = head;

    // This could someday be made more efficient - right now,
    // we just do a search and destroy.
    while (tmp != NULL)
    {
        if (iter.getCurrElem() == tmp)
        {
            found = true;
            break;
        }
        prev = tmp;
        tmp  = tmp->next_elem();
    }

    if (found)
    {
        SEDRIS_List_Elem<T> *tmp2 = tmp->next_elem();

        if (prev)
            prev->set_next_elem(tmp->next_elem());
        else // since prev == NULL, tmp == head
            head = head->next_elem();

        if (tmp == tail)
            tail = prev;

        --population;

        delete tmp;

        return SEDRIS_Iterator<T>(this, tmp2);
    }
    else
    {
        return SEDRIS_Iterator<T>(this, NULL);
    }
}

template<class T>
void SEDRIS_List<T>::addFirst(const T& elem)
{
    SEDRIS_List_Elem<T> *new_elem = new SEDRIS_List_Elem<T>(elem);

    new_elem->set_next_elem(head);

    if (!head)
    {
        head = tail = new_elem;
    }
    else
    {
        head = new_elem;
    }
    ++population;
}


template<class T>
void SEDRIS_List<T>::addLast(const T& elem)
{
    SEDRIS_List_Elem<T> *new_elem = new SEDRIS_List_Elem<T>(elem);

    if (tail)
    {
        tail->set_next_elem(new_elem);
        tail = tail->next_elem();
    }
    else
    {
        head = tail = new_elem;
    }
    ++population;
}

template<class T>
void SEDRIS_List<T>::addAfter(long n, const T& elem)
{

    if (n < 0)
        addFirst(elem);
    else if (population <= n || population == 0)
        addLast(elem);
    else
    {
        SEDRIS_List_Elem<T> *new_elem = new SEDRIS_List_Elem<T>(elem);
        SEDRIS_List_Elem<T> *tmp, *hold;

        tmp  = head;
        for (long i=0; i<n; ++i)
            tmp  = tmp->next_elem();


        hold = tmp->next_elem();
        tmp->set_next_elem(new_elem);
        new_elem->set_next_elem(hold);

        ++population;
    }
}

template<class T>
void SEDRIS_List<T>::removeAll()
{
    SEDRIS_List_Elem<T> *tmp;
    while (head)
    {
        tmp  = head;
        head = head->next_elem();
        delete tmp;
    }
    population = 0;
    tail = head = NULL;
}

#endif // _SE_LISTS_HH_INCLUDED defined
