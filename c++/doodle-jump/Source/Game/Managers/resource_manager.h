#ifndef RESOURCE_MANAGER_H_INCLUDED
#define RESOURCE_MANAGER_H_INCLUDED

#include <memory>
#include <cassert>

template < typename Key, typename Resource >
class Resource_Manager
{
    using ResPtr = std::unique_ptr<Resource>;

    public:
        void load( const std::string fileName, Key id  )
        {
            ResPtr resource = std::make_unique<Resource>();

            if ( !resource->loadFromFile( fileName ) )
            {
                throw std::runtime_error ( "Could not load resource from: " + fileName + "!" );
            }

            insert ( id, std::move(resource) );
        }

        const Resource& get ( Key id ) const
        {
            assert( m_resources.at ( id ) );
            return *m_resources.at ( id );
        }

    private:
        void insert ( Key id, ResPtr resource )
        {
            auto inserted = m_resources.insert( std::make_pair( id, std::move ( resource ) ) );
            assert ( inserted.second );
        }


        std::map<Key, ResPtr> m_resources;
};

#endif // RESOURCE_MANAGER_H_INCLUDED
