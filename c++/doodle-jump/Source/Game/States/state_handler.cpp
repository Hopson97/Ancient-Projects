#include "state_handler.h"

void State_Handler::pushState( StatePtr state )
{
	m_states.push(std::move(state));
}


void State_Handler::popState()
{
	if ( !m_states.empty() )
	{
		m_states.pop();
	}
}

StatePtr& State_Handler::peekState()
{
	return m_states.top();
}
