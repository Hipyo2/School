defmodule InClass.Company.Developer do
  use Ecto.Schema
  import Ecto.Changeset
  alias InClass.Company.{Area, Assignment, Task}

  schema "developers" do
    field :email, :string
    field :first_name, :string
    field :last_name, :string
    field :zipcode, :integer
    belongs_to(:area, Area)
    has_many(:assignments, Assignment)
    many_to_many(:tasks, Task, join_through: Assignment)
    timestamps()
  end

  @doc false
  def changeset(developer, attrs) do
    developer
    |> cast(attrs, [:first_name, :last_name, :email, :zipcode, :area_id])
    |> validate_required([:first_name, :last_name, :email, :zipcode, :area_id])
  end
end
