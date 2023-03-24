defmodule InClass.Company.Zipcode do
  defstruct city: nil, state_fullname: nil, developer: nil

  @url "https://service.zipapi.us/zipcode/"
  @url2 "/?X-API-KEY=js-cdc30b207daa769356b5c60286efddf9&fields=geolocation,population"

  def get_by_developer(developer) do
    {:ok, response} = HTTPoison.get(@url <> to_string(developer.zipcode) <> @url2)
    {:ok, values} = Jason.decode(response.body)
    #{:ok, test} = Jason.decode(values, keys: :atoms)
    #{:ok, values} = Jason.decode(response.body)
    values["data"]
    #city = values.data.city
    #state = values.data.state
  end
end
