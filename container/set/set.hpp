#ifndef __SET__
#define __SET__
#include "Joe_RBtree.hpp"

//   set <key,  Compare, Alloc>
//rbtree <key,  key,     idenity<key>,  Compare=less<key>,  Alloc=allocator<key>    >

template<typename key, typename Compare=std::less<key>, typename Alloc=Joe::allocator< rb_tree_node<key> >  >
class set
{
public:
    using value_type       = key;
    using const_value_type = const key;
    using key_type         = key;
    using key_compare      = Compare;
    using value_compare    = Compare;
    using size_type        = size_t;
    using difference_type  = ptrdiff_t;
    using allocator_type   = Alloc;

private:
    using rb_type = rb_tree<key_type, value_type, value_type, key_compare, Alloc  >;
    rb_type true_tree;
public:
    using iterator               =  typename rb_type::const_iterator;
    using const_iterator         =  typename rb_type::const_iterator;
    using re_iterator            =  typename rb_type::const_reverse_iterator;
    using const_re_iterator      =  typename rb_type::const_reverse_iterator;

public:
    iterator            begin()
    {
        return true_tree.cbegin();
    }
    const_iterator      begin()const noexcept
    {
        return true_tree.cbegin();
    }
    iterator              end()
    {
        return true_tree.cend();
    }
    const_iterator        end()const noexcept
    {
        return true_tree.cend();
    }
    const_iterator     cbegin()const noexcept
    {
        return true_tree.cbegin();
    }
    const_iterator       cend()const noexcept
    {
        return true_tree.cend();
    }

    re_iterator        rbegin()
    {
        return true_tree.crbegin();
    }
    const re_iterator  rbegin()const noexcept
    {
        return true_tree.crbegin();
    }
    re_iterator          rend()
    {
        return true_tree.crend();
    }
    const re_iterator    rend()const noexcept
    {
        return true_tree.crend();
    }
    const_re_iterator crbegin()const noexcept
    {
        return true_tree.crbegin();
    }
    const_re_iterator   crend()const noexcept
    {
        return true_tree.crend();
    }

public:

    const_iterator find(const_value_type& val)const
    {
        return true_tree.find(val);
    };
    iterator       find(const_value_type& val)
    {
        return true_tree.find(val);
    };

    bool           empty()
    {
        return true_tree.empty();
    }

    pair<iterator,bool> emplace ();
    void           clear()noexcept
    {
        return true_tree.clear();
    }
    size_type      max_size()
    {
        return true_tree.max_size();
    }
    size_type      size    ()
    {
        return true_tree.size();
    }


    void operator=(const_value_type& x)
    {
        this->clear();
        this->insert(x.begin(), x.end());
    }

    void swap(set& x)
    {
        true_tree.swap(x.true_tree);
    }

    iterator       erase(const_iterator pos);
    iterator       erase(const_iterator first, const_iterator last);
    size_type      erase(const_value_type& x);
    size_type      count(const_value_type& val);

    allocator_type     get_allocator()const noexcept
    {
        return true_tree.get_allocator();
    }

    const_iterator     lower_bound(const value_type& val)
    {
        return true_tree.lower_bound(val);	   // return the first element of set which is >= val.
    }
    const_iterator     lower_bound(const value_type& val)const
    {
        return true_tree.lower_bound(val);
    }

    const_iterator     upper_bound(const value_type& val)
    {
        return true_tree.upper_bound(val);	   //return the first element of set which is > val.
    }
    const_iterator     upper_bound(const value_type& val)const
    {
        return true_tree.upper_bound(val);
    }

    value_compare      value_comp()const
    {
        return true_tree.value_compare();
    }
    key_compare        key_comp()  const
    {
        return true_tree.key_comp();
    }


    inline pair<iterator, bool>   insert(const value_type&& val)
    {
        return true_tree.insert_unique(val);
    }
    inline pair<iterator,bool>    insert(value_type&& val)
    {
        return true_tree.insert_unique(val);
    }
    inline void                   insert(iterator first, iterator last)
    {
        true_tree.insert_unique(first, last);
    }
    inline iterator               insert(const_iterator position, const value_type& val)
    {
        return true_tree.insert_unique(position, val);
    }
    inline iterator               insert(const_iterator position, value_type&& val)
    {
        return true_tree.insert_unique(position, val);
    }
    inline void                          insert(initializer_list<value_type> il)
    {
        true_tree.insert_unique(il);
    }

    inline pair<iterator, bool>      emplace(const value_type& val)
    {
        return true_tree.emplace_unique(val);
    };
    inline iterator                  emplace_hint(iterator tmp, const value_type& val)
    {
        return true_tree.insert_unique(tmp, val);
    };
public:
    set() = default;
    set(initializer_list<value_type> il):set()
    {
        for(auto& i: il)
            true_tree.insert_unique(i);
    }
    ~set() = default;
};

template<typename key, typename Compare, typename Alloc >
typename set<key,  Compare, Alloc>::size_type
set<key,  Compare, Alloc>::count(const_value_type& val)
{
    size_type count = 0;
    for(auto i = begin(); i != end(); ++i)
        if(*i == val)
            ++count;

    return count;
}

#endif //__SET__








