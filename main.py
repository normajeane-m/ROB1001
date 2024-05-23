import streamlit as st

st.title('기초로봇공학개론 수업(2024.05.23)')

# Using the "with" syntax
with st.form(key='my_form'):
	text_input = st.text_input(label='Enter some text')
	submit_button = st.form_submit_button(label='Submit')
